// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
// Difficulty: Medium
// Tags: Arrays, Hashing, Bit Manipulation

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int count=0;
        unordered_map<int,int> mp;
        
        mp[0]=1;
        int xr=0;
        for(int num: arr){
            xr=xr^num;
            
            int req=k^xr;
            
            if(mp.find(req)!=mp.end()){
                count += mp[req];
            }
            
            mp[xr]++;
        }
        
        return count;
    }
};