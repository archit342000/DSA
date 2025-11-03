// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Difficulty: Medium
// Tags: Stacks

class Solution {
    int prec(char ch){
        if(ch == '^'){
            return 3;
        }
        if(ch=='*' || ch=='/'){
            return 2;
        }
        if(ch=='+' || ch=='-'){
            return 1;
        }
        return -1;
    }
    bool isRightAssociative(char ch){
        return ch == '^';
    }
  public:
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string res="";
        
        for(char ch: s){
            if(isalnum(ch)){
                res+=ch;
            }
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(st.top()!='('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() &&
                       (prec(st.top()) > prec(ch) ||
                       (prec(st.top()) == prec(ch) && !isRightAssociative(ch)))) {
                    res += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
