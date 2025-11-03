// https://leetcode.com/problems/power-of-two/description/
// Difficulty: Easy
// Tags: Bit Manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        int count = 0;
        for(int i=1; i<=31; i++){
            if((n&1)==1){
                count++;
            }
            n = n >> 1;
        }
        return count==1;
    }
};
