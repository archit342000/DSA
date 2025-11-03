// https://leetcode.com/problems/maximum-product-subarray/description/
// Difficulty: Medium
// Tags: Arrays, Dynamic Programming

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int minProd = nums[0];
        int maxProd = nums[0];
        int result = nums[0];

        for(int i=1; i<n; i++){
            int temp=minProd;
            minProd = min(minProd*nums[i], min(maxProd*nums[i], nums[i]));
            maxProd = max(maxProd*nums[i], max(temp*nums[i], nums[i]));
            result = max(result, maxProd);
        }

        return result;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long pre = 1, suff = 1, maxProd = LONG_MIN;
        cout << maxProd;
        for(int i=0; i<n; i++){
            if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre *= nums[i];
            suff *= nums[n-1-i];
            maxProd = max(maxProd, max(pre, suff));
            
        }
        return maxProd;
    }
};