// https://leetcode.com/problems/maximum-subarray/description/
// Difficulty: Easy
// Tags: Array, Algorithms

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int x: nums){
            sum += x;

            maxSum = max(maxSum, sum);

            if(sum<0){
                sum = 0;
            }
        }

        return maxSum;
    }
};