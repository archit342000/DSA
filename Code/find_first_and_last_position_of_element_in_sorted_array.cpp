// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();

        int l1=0, r1=n-1;

        while(l1<=r1){
            int m1=(l1+r1)/2;

            if(nums[m1]<=target){
                l1=m1+1;
            }
            else{
                r1=m1-1;
            }
        }

        if(r1==-1 || nums[r1]!=target){
            return {-1, -1};
        }

        int l2=0, r2=n-1;

        while(l2<=r2){
            int m2=(l2+r2)/2;

            if(nums[m2]>=target){
                r2=m2-1;
            }
            else{
                l2=m2+1;
            }
        }

        return {l2, r1};
    }
};