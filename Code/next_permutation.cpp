// https://leetcode.com/problems/next-permutation/description/
// Difficulty: Medium
// Tags: Arrays

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int p = -1;

        for(int i = n-2; i>=0; i--){
            if(nums[i+1]>nums[i]){
                p = i;
                break;
            }
        }

        if(p==-1){
            reverse(nums.begin(), nums.end());
        }
        else{
            int i;
            for(i=n-1; i>p; i--){
                if(nums[i]>nums[p]){
                    break;
                }
            }

            swap(nums[i], nums[p]);
            reverse(nums.begin()+p+1, nums.end());
        }
    }
};