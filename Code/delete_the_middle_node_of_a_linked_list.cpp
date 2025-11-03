// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
// Difficulty: Medium
// Tags: Linked Lists, Two Pointers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode *slow=head, *fast=head, *prevSlow=NULL;

        while(fast && fast->next){
            prevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *delNode=prevSlow->next;
        prevSlow->next=prevSlow->next->next;
        delNode->next=NULL;
        delete delNode;
        return head;
    }
};