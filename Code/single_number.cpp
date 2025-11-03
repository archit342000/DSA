// https://leetcode.com/problems/single-number/description/
// Difficulty: Easy
// Tags: Array, Bit Manipulation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;

        for(int x: nums){
            xr = xr ^ x;
        }

        return xr;
    }
};