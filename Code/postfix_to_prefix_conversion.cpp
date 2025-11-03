// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
// Difficulty: Medium
// Tags: Stacks, Recursion

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n=post_exp.size();
        stack<string> st;
        
        for(int i=0; i<n; i++){
            char ch=post_exp[i];
            
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push(ch+s2+s1);
            }
        }
        
        return st.top();
    }
};

// User function Template for C++

class Solution {
    string helper(string &post_exp, int &i){
        char ch=post_exp[i--];
        
        if(isalnum(ch)){
            return string(1,ch);
        }
        else{
            string s1=helper(post_exp, i);
            string s2=helper(post_exp, i);
            return ch+s2+s1;
        }
    }
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int i=post_exp.size()-1;
        return helper(post_exp, i);
    }
};