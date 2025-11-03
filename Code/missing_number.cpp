// https://leetcode.com/problems/missing-number/description/
// Difficulty: Easy
// Tags: Array, Math, Bit Manipulation

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for(int i=0; i<n; i++){
            xr = xr ^ (i+1);
            xr = xr ^ (nums[i]);
        }
        return xr;
    }
};