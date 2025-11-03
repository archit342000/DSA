// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
// Difficulty: Medium
// Tags: Arrays, Stacks, Monotonic Stacks

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ans;
        for(int i=0; i<queries; i++){
            int idx=indices[i];
            
            stack<int> st;
            
            for(int j=idx+1; j<n; j++){
                st.push(arr[j]);
                while(!st.empty() && st.top()<=arr[idx]){
                    st.pop();
                }
            }
            
            ans.push_back(st.size());
        }
        
        return ans;
    }
};

class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        int q=indices.size();
        vector<int> ans(q, 0);
        
        for(int i=0; i<q; i++){
            int idx=indices[i];
            
            int count=0;
            
            for(int j=idx+1; j<n; j++){
                if(arr[j]>arr[idx]){
                    count++;
                }
            }
            
            ans[i]=count;
        }
        
        return ans;
    }
};