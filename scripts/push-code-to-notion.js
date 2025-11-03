import fs from "fs/promises";
import path from "path";
import { execSync } from "child_process";
import { Client } from "@notionhq/client";

const notion = new Client({ auth: process.env.NOTION_API_KEY });
const ROOT_PAGE_ID = process.env.NOTION_ROOT_PAGE_ID;
const ROOT_DIR = "Code";
const BASE = process.env.GITHUB_BASE || "HEAD~1";
const HEAD = process.env.GITHUB_SHA || "HEAD";

// Map extensions → Notion code languages
const LANG = {
  ".js":"javascript",".ts":"typescript",".tsx":"typescript",".jsx":"javascript",
  ".py":"python",".java":"java",".cpp":"cpp",".c":"c",".cs":"csharp",".rb":"ruby",
  ".go":"go",".rs":"rust",".php":"php",".kt":"kotlin",".swift":"swift",".sh":"bash",
  ".json":"json",".yml":"yaml",".yaml":"yaml",".sql":"sql",".md":"markdown"
};

const sleep = (ms) => new Promise(r => setTimeout(r, ms));
async function notionCall(fn, ...args) {
  for (let i = 0; i < 5; i++) {
    try { return await fn(...args); }
    catch (e) {
      if ((e.status === 429 || e.code === "rate_limited") && i < 4) {
        await sleep(500 * (i + 1));
        continue;
      }
      throw e;
    }
  }
}

const useHierarchy = true;
const folderCache = new Map();

async function ensureFolderPages(relPath) {
  if (!useHierarchy) return ROOT_PAGE_ID;
  const parts = relPath.split("/").slice(0, -1); // folders only
  let parentId = ROOT_PAGE_ID;
  for (const folder of parts) {
    const key = `${parentId}/${folder}`;
    if (folderCache.has(key)) { parentId = folderCache.get(key); continue; }

    const search = await notionCall(notion.search.bind(notion), {
      query: folder, page_size: 10,
      filter: { value: "page", property: "object" }
    });

    let pageId = null;
    for (const r of (search.results || [])) {
      const t = r.properties?.title?.title?.[0]?.plain_text
            || r.properties?.Name?.title?.[0]?.plain_text || "";
      if (t === folder && r.parent?.page_id === parentId) { pageId = r.id; break; }
    }

    if (!pageId) {
      const created = await notionCall(notion.pages.create.bind(notion.pages), {
        parent: { page_id: parentId },
        properties: { title: [{ type: "text", text: { content: folder } }] }
      });
      pageId = created.id;
    }

    folderCache.set(key, pageId);
    parentId = pageId;
    await sleep(150);
  }
  return parentId;
}

async function findPageByTitle(title, parentId) {
  const res = await notionCall(notion.search.bind(notion), {
    query: title, page_size: 10,
    filter: { value: "page", property: "object" }
  });
  for (const r of (res.results || [])) {
    const t = r.properties?.title?.title?.[0]?.plain_text
          || r.properties?.Name?.title?.[0]?.plain_text || "";
    if (t === title && (r.parent?.page_id === parentId)) return r;
  }
  return null;
}

async function replaceWithCodeBlocks(pageId, blocks) {
  // Delete existing children
  const children = await notionCall(notion.blocks.children.list.bind(notion.blocks.children), { block_id: pageId, page_size: 100 });
  for (const b of children.results) {
    await notionCall(notion.blocks.delete.bind(notion.blocks), { block_id: b.id });
    await sleep(120);
  }
  // Append new blocks
  for (const blk of blocks) {
    await notionCall(notion.blocks.children.append.bind(notion.blocks.children), {
      block_id: pageId,
      children: [blk]
    });
    await sleep(150);
  }
}

function toCodeBlocks(content, lang) {
  const MAX = 80000; // safe chunk size under Notion block limits
  if (content.length <= MAX) {
    return [{
      object: "block",
      type: "code",
      code: { language: lang || "plain text", rich_text: [{ type: "text", text: { content } }] }
    }];
  }
  const out = [];
  let i = 0, part = 1;
  while (i < content.length) {
    const chunk = content.slice(i, i + MAX);
    out.push({
      object: "block",
      type: "code",
      code: {
        language: lang || "plain text",
        caption: [{ type: "text", text: { content: `Part ${part}` } }],
        rich_text: [{ type: "text", text: { content: chunk } }]
      }
    });
    i += MAX; part++;
  }
  return out;
}

function listChangedPaths() {
  const diff = execSync(`git diff --name-status ${BASE} ${HEAD}`, { encoding: "utf8" })
    .trim()
    .split("\n")
    .filter(Boolean);

  const changed = [];
  const removed = [];
  for (const line of diff) {
    const [status, ...rest] = line.split(/\s+/);
    const file = rest.pop(); // for RENAME we get old new; last is new
    if (!file || !file.startsWith(`${ROOT_DIR}/`)) continue;
    if (status.startsWith("D")) removed.push(file);
    else changed.push(file);
  }
  return { changed, removed };
}

(async () => {
  try {
    const { changed, removed } = listChangedPaths();

    // Archive pages for deleted files
    for (const filePath of removed) {
      const rel = filePath.replace(/^Code\//, "");
      const parentId = await ensureFolderPages(rel);
      const page = await findPageByTitle(rel, parentId);
      if (page) {
        await notionCall(notion.pages.update.bind(notion.pages), { page_id: page.id, archived: true });
        await sleep(120);
      }
    }

    // Create/update pages for changed files
    for (const filePath of changed) {
      const content = await fs.readFile(filePath, "utf8");
      const rel = filePath.replace(/^Code\//, "");
      const ext = path.extname(filePath).toLowerCase();
      const lang = LANG[ext] || "plain text";

      const parentId = await ensureFolderPages(rel);
      let page = await findPageByTitle(rel, parentId);

      if (!page) {
        page = await notionCall(notion.pages.create.bind(notion.pages), {
          parent: { page_id: parentId },
          properties: { title: [{ type: "text", text: { content: rel } }] }
        });
        await sleep(120);
      }

      const blocks = toCodeBlocks(content, lang);
      await replaceWithCodeBlocks(page.id, blocks);
    }

    console.log(`Synced: ${changed.length} updated/added, ${removed.length} removed`);
  } catch (e) {
    console.error(e);
    process.exit(1);
  }
})();
