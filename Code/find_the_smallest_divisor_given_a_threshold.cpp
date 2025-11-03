// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int l=1;
        int r=*max_element(nums.begin(), nums.end());

        while(l<=r){
            int m=(l+r)/2;

            int c=0;

            for(int num: nums){
                c += ((num+m-1)/m);

                if(c>threshold){
                    break;
                }
            }

            if(c<=threshold){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l;
    }
};