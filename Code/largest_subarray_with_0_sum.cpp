// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Difficulty: Easy
// Tags: Arrays, Hashing

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int maxLen = 0;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum==0){
                maxLen = i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    maxLen = max(maxLen, i-mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        
        return maxLen;
    }
};