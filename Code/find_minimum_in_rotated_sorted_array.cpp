// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        int l=0, r=n-1;

        while(l<=r){

            int m=(l+r)/2;

            if(nums[l]<=nums[r]){
                break;
            }

            if(nums[m]<=nums[r]){
                r=m;
            }
            else{
                l=m+1;
            }
        }

        return nums[l];
    }
};