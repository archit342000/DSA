// https://leetcode.com/problems/longest-common-prefix/description/
// Difficulty: Easy
// Tags: Strings, Arrays

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];

        for(int i=1; i<strs.size(); i++){
            int m=ans.size();
            int n=strs[i].size();

            int j=0, k=0;
            while(j<m && k<n){
                if(ans[j]==strs[i][k]){
                    j++;
                    k++;
                }
                else{
                    break;
                }
            }

            ans = ans.substr(0, j);
        }

        return ans;
    }
};

