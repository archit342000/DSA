// https://leetcode.com/problems/valid-palindrome/description/
// Difficulty: Easy

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(!isalnum(s[start])){
                start++;
            }
            else if(!isalnum(s[end])){
                end--;
            }
            else{
                if(tolower(s[start])!=tolower(s[end])){
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindromeUtil(string &s, int start, int end){
        if(start>=end){
            return true;
        }
        if(!isalnum(s[start])){
            return isPalindromeUtil(s, start+1, end);
        }
        if(!isalnum(s[end])){
            return isPalindromeUtil(s, start, end-1);
        }
        if(tolower(s[start])!=tolower(s[end])){
            return false;
        }
        return isPalindromeUtil(s, start+1, end-1);
    }
    bool isPalindrome(string s) {
        return isPalindromeUtil(s, 0, s.size()-1);
    }
};
