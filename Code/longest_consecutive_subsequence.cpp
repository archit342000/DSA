// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// Difficulty: Easy
// Tags: Arrays, Hashing

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int maxLen = 1;
        unordered_map<int, int> mp;
        
        for(int x: arr){
            mp[x] = 1;
        }
        
        for(int x: arr){
            if(mp[x]!=1){
                continue;
            }
            
            int len = 1;
            
            // Check left
            int start = x-1;
            while(mp[start]==1){
                mp[start--]=0;
                len++;
            }
            
            start = x+1;
            while(mp[start]==1){
                mp[start++]=0;
                len++;
            }
            
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};