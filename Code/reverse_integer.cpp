// https://leetcode.com/problems/reverse-integer/description/
// Difficulty: Easy
// Tags: Math

class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0){
            int d=x%10;
            x=x/10;
            if(rev>INT_MAX/10){
                return 0;
            }
            else if(rev<INT_MIN/10){
                return 0;
            }
            rev=rev*10+d;
        }
        return rev;
    }
};
