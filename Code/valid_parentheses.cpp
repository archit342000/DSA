// https://leetcode.com/problems/valid-parentheses/description/
// Difficulty: Easy
// Tags: Strings, Stacks

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s){
            if(ch==')'){
                if(st.empty() || st.top()!='('){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else if(ch==']'){
                if(st.empty() || st.top()!='['){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else if(ch=='}'){
                if(st.empty() || st.top()!='{'){
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        return st.empty();
    }
};