// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
// Difficulty: Medium
// Tags: Strings, Hashing, Counting

class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int count =0;

        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;

                int minFreq=INT_MAX, maxFreq=INT_MIN;

                for(int k=0; k<26; k++){
                    if(freq[k]!=0){
                        minFreq=min(minFreq, freq[k]);
                        maxFreq=max(maxFreq, freq[k]);
                    }
                }

                count += (maxFreq-minFreq);
            }
        }

        return count;
    }
};