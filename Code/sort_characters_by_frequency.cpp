// https://leetcode.com/problems/sort-characters-by-frequency/description/
// Difficulty: Medium
// Tags: Strings, Sorting, Hashing

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> mp(62, {0, 'a'});

        int n=s.size();

        for(int i=0; i<n; i++){
            char ch=s[i];
            int idx=0;
            if(ch>='0' && ch<='9'){
                idx=ch-'0';
            }
            if(ch>='a' && ch<='z'){
                idx=ch-'a'+10;
            }
            if(ch>='A' && ch<='Z'){
                idx=ch-'A'+26+10;
            }
            pair<int,char> p=mp[idx];
            p.first++;
            p.second=ch;
            mp[idx]=p;
        }

        sort(mp.begin(), mp.end(), greater<pair<int,char>>());

        string out="";
        for(int i=0; i<62; i++){
            pair<int,char> p=mp[i];
            for(int j=0; j<p.first; j++){
                out+=p.second;
            }
        }

        return out;
    }
};