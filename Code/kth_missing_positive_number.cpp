// https://leetcode.com/problems/kth-missing-positive-number/description/
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int l=0;
        int r=n-1;

        while(l<=r){
            int m=(l+r)/2;

            int miss = arr[m]-(m+1);

            if(miss>=k){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l+k;
    }
};
