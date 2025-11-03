// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1
// Difficulty: Medium
// Tags: Stacks, Recursion

class Solution {
  public:
    string preToPost(string pre_exp) {
        int n=pre_exp.size();
        stack<string> st;
        
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
                st.push(s1+s2+ch);
            }
        }
        
        return st.top();
    }
};

class Solution {
  public:
    string helper(string &pre_exp, int &i){
        char ch=pre_exp[i++];
        
        if(isalnum(ch)){
            return string(1,ch);
        }
        else{
            string s1=helper(pre_exp, i);
            string s2=helper(pre_exp, i);
            return s1+s2+ch;
        }
    }
    string preToPost(string pre_exp) {
        int i=0;
        return helper(pre_exp, i);
    }
};