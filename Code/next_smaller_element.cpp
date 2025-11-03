// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
// Difficulty: Easy
// Tags: Arrays, Stacks, Monotonic Stacks

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        
        stack<int> st;
        vector<int> ans(n, -1);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i]=st.top();
            }
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};