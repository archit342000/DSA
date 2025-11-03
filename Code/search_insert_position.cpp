// https://leetcode.com/problems/search-insert-position/description/
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0, r=n-1;

        while(l<=r){
            int m=(l+r)/2;

            if(nums[m]>=target){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l;
    }
};