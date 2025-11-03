// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Difficulty: Medium
// Tags: Strings, Hashing, Sliding Window

class Solution {
  public:
    int atMost(string &s, int k){
        vector<int> freq(26, 0);
        int left=0, right=0;
        int distinct=0;
        int ans=0;
        int n=s.size();
        
        while(right<n){
            int idx=s[right]-'a';
            freq[idx]++;
            
            if(freq[idx]==1){
                distinct++;
            }
            
            while(distinct>k){
                int idx2=s[left++]-'a';
                freq[idx2]--;
                if(freq[idx2]==0){
                    distinct--;
                }
            }
            
            ans += right-left+1;
            right++;
        }
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atMost(s, k) - atMost(s, k-1);
    }
};