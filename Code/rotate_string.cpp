// https://leetcode.com/problems/rotate-string/description/
// Difficulty: Easy
// Tags: Strings

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();

        if(n!=m){
            return false;
        }

        goal += goal;

        for(int i=0; i<n; i++){
            string temp = goal.substr(i, n);

            if(temp==s){
                return true;
            }
        }

        return false;
    }
};