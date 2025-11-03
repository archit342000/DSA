// https://leetcode.com/problems/sqrtx/description/
// Difficulty: Easy
// Tags: Binary Search, Math

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1){
            return x;
        }

        long long int l=1;
        long long int r=x/2;

        while(l<=r){
            long long int m = (l+r)/2;

            long long int sqr = m*m;

            if(sqr<=x){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return r;
    }
};

