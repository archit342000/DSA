// https://leetcode.com/problems/remove-outermost-parentheses/description/
// Difficulty: Medium
// Tags: Strings, Stacks

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        string out="";

        for(char ch: s){
            if(ch=='('){
                if(open>0){
                    out += ch;
                }
                open++;
            }
            else{
                if(open>1){
                    out += ch;
                }
                open--;
            }
        }

        return out;
    }
};

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for(char ch: s){
            if(ch=='('){
                if(!st.empty()){
                    ans+=ch;
                }
                st.push(ch);
            }
            else{
                st.pop();
                if(!st.empty()){
                    ans+=ch;
                }
            }
        }

        return ans;
    }
};