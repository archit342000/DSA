// https://leetcode.com/problems/largest-odd-number-in-string/description/
// Difficulty: Easy
// Tags: Strings, Math, Greedy

class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();

        for(int i=n-1; i>=0; i--){
            if((num[i]-'0')%2){
                break;
            }
            else{
                num.pop_back();
            }
        }

        return num;
    }
};