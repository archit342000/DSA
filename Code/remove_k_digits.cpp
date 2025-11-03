// https://leetcode.com/problems/remove-k-digits/description/
// Difficulty: Medium
// Tags: Arrays, Stacks, Monotonic Stacks, Greedy

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();

        if(k>=n){
            return "0";
        }

        stack<char> st;

        for(int i=0; i<n; i++){
            while(k>0 && !st.empty() && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }

        if(ans.empty()){
            return "0";
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};