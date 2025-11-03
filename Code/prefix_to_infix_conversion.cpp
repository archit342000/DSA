// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
// Difficulty: Medium
// Tags: Stacks, Recursion

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        int n=pre_exp.size();
        
        for(int i=n-1; i>=0; i--){
            char ch=pre_exp[i];
            
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push("("+s1+ch+s2+")");
            }
        }
        
        return st.top();
    }
};

// User function Template for C++

class Solution {
    string helper(string &pre_exp, int &i){
        char ch=pre_exp[i++];
        
        if(isalnum(ch)){
            return string(1,ch);
        }
        else{
            string s1=helper(pre_exp, i);
            string s2=helper(pre_exp, i);
            return "("+s1+ch+s2+")";
        }
    }
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        int i=0;
        return helper(pre_exp, i);
    }
};