// https://leetcode.com/problems/palindrome-number/description/
// Difficulty: Easy
// Tags: Mathematical

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long rev=0;
        int x_2=x;

        while(x_2!=0){
            int d=x_2%10;
            x_2/=10;
            rev=rev*10+d;
        }

        return rev==x;
    }
};
