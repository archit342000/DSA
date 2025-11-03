// https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1
// Difficulty: Medium
// Tags: Stacks

class Solution {
    int prec(char ch){
        if(ch=='^'){
            return 3;
        }
        if(ch=='/' || ch=='*'){
            return 2;
        }
        if(ch=='+' || ch=='-'){
            return 1;
        }
        return 0;
    }
    bool isRightAssociative(char ch){
        return ch == '^';
    }
  public:
    string infixToPrefix(string &s) {
        // code here
        reverse(s.begin(), s.end());
        for(char &c: s){
            if(c=='('){
                c=')';
            }
            else{
                if(c==')'){
                    c='(';
                }
            }
        }
        
        int n=s.size();
        string ans="";
        stack<char> st;
        
        for(char ch: s){

            if(isalnum(ch)){
                ans += ch;
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && (prec(st.top())>prec(ch) || (prec(st.top())==prec(ch) && isRightAssociative(ch)))){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
