// https://leetcode.com/problems/divide-two-integers/description/
// Difficulty: Medium
// Tags: Bit Manipulation

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool isPos = (dividend>0 == divisor>0);
        unsigned int a = dividend==INT_MIN?(unsigned int)(INT_MAX)+1:abs(dividend);
        unsigned int b = divisor==INT_MIN?(unsigned int)(INT_MAX)+1:abs(divisor);
        unsigned int ans = 0;
        while(a>=b){
            int q=0;
            while(a>(b<<(q+1))){
                q++;
            }
            ans += (1<<q);
            a = a - (b<<q);
        }
        if(ans==(1<<31) && isPos){
            return INT_MAX;
        }
        return isPos?ans:-ans;
    }
};