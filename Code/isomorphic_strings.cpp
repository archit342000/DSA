// https://leetcode.com/problems/isomorphic-strings/description/
// Difficulty: Easy
// Tags: Strings, Hashing

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;

        int m=s.size();
        int n=t.size();

        if(m!=n){
            return false;
        }

        for(int i=0; i<m; i++){
            char ch1=s[i];
            char ch2=t[i];

            if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2){
                return false;
            }

            if(mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1){
                return false;
            }

            mp1[ch1]=ch2;
            mp2[ch2]=ch1;
        }

        return true;
    }
};