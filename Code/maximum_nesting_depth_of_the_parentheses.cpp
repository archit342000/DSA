// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// Difficulty: Easy
// Tags: Strings, Stacks

class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int max_open=0;

        for(char ch: s){
            if(ch=='('){
                open++;
                max_open=max(max_open, open);
            }
            else if(ch==')'){
                open--;
            }
        }

        return max_open;
    }
};

class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxCount=0;

        for(char ch: s){
            if(ch=='('){
                st.push(ch);
                maxCount=max(maxCount, int(st.size()));
            }
            if(ch==')'){
                st.pop();
            }
        }

        return maxCount;
    }
};