// https://leetcode.com/problems/split-array-largest-sum/description/
// Difficulty: Hard
// Tags: Arrays, Binary Search, Greedy

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();

        int l=*max_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);

        while(l<=r){
            int m=(l+r)/2;

            int count=0;
            int sum=0;

            for(int num: nums){
                if(sum+num > m){
                    count++;
                    sum=0;
                }
                sum+=num;
            }

            if(sum!=0){
                count++;
            }

            if(count<=k){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l;
    }
};