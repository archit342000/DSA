// https://leetcode.com/problems/valid-anagram/description/
// Difficulty: Easy
// Tags: Strings, Sorting, Hashing

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.size();
        int n=t.size();

        if(m!=n){
            return false;
        }

        vector<int> freq(26, 0);

        for(char ch: s){
            freq[ch-'a']++;
        }

        for(char ch: t){
            freq[ch-'a']--;

            if(freq[ch-'a']<0){
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m=s.size();
        int n=t.size();

        if(m!=n){
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }
};