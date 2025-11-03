// https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// Tags: Arrays, Hashing, Prefix Sum

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        int sum = 0;

        mp[0] = 1;

        for(int num: nums){
            sum += num;

            int req = sum-k;

            if(mp.find(req)!=mp.end()){
                count += mp[req];
            }

            mp[sum]++;
        }

        return count;
    }
};