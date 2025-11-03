// https://leetcode.com/problems/longest-palindromic-substring/description/
// Difficulty: Medium
// Tags: Strings, Two Pointers

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        int start=0, end=0;

        for(int i=0; i<n; i++){
            int odd=0;
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            odd = right-left-1;

            int even=0;
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            even = right-left-1;

            int maxLen = max(odd, even);

            if(maxLen > (end-start+1)){
                start = i-(maxLen-1)/2;
                end = i+(maxLen)/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};