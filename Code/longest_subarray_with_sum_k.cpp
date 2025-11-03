// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// Difficulty: Medium
// Tags: Arrays, Hashing, Prefix Sum

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        
        int sum = 0;
        int max_len = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum == k){
                max_len = i+1;
            }
            else{
                int req = sum - k;
                if(mp.find(req)!=mp.end()){
                    max_len = max(max_len, i-mp[req]);
                }
            }
            
            if(mp.find(sum)==mp.end()){
                mp[sum] = i;
            }
        }
        
        return max_len;
    }
};