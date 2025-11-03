// https://leetcode.com/problems/sum-of-subarray-minimums/description/
// Difficulty: Medium
// Tags: Arrays, Stacks, Monotonic Stacks

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);

        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(!st.empty()){
                pse[i]=st.top();
            }

            st.push(i);
        }

        stack<int> st2;

        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }

            if(!st2.empty()){
                nse[i]=st2.top();
            }

            st2.push(i);
        }

        int ans=0;

        for(int i=0; i<n; i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            ans = (ans+ (left*right*1LL*arr[i])%mod)%mod;
        }

        return ans;
    }
};