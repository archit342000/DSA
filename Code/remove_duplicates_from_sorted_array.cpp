// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Difficulty: Easy
// Tags: Array, Two Pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i=0, j=1;

        while(j<n){
            if(nums[i]!=nums[j]){
                swap(nums[++i], nums[j]);
            }
            j++;
        }

        return i+1;
    }
};