// https://leetcode.com/problems/move-zeroes/description/
// Difficulty: Easy
// Tags: Array, Two Pointers

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=-1, j=0;

        while(j<n){
            if(nums[j]!=0){
                swap(nums[++i], nums[j]);
            }
            j++;
        }
    }
};