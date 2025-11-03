// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0, r=n-1;

        while(l<=r){
            int m=(l+r)/2;

            if(nums[m]==target){
                return m;
            }
            
            if(nums[m]>target){
                if(nums[l]<=target || nums[l]>nums[m]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(nums[r]>=target || nums[r]<nums[m]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }

        return -1;
    }
};
