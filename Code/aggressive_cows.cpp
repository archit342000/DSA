// http://geeksforgeeks.org/problems/aggressive-cows/1
// Difficulty: Medium
// Tags: Arrays, Binary Search, Sorting

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int n=stalls.size();
        
        int l = 1;
        int r = stalls[n-1] - stalls[0];
        
        while(l<=r){
            int m=(l+r)/2;
            
            int cows=1;
            int dist=0;
            
            for(int i=1; i<n; i++){
                dist += (stalls[i]-stalls[i-1]);
                
                if(dist>=m){
                    cows++;
                    dist=0;
                }
                
                if(cows>k){
                    break;
                }
            }
            
            if(cows>=k){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        
        return r;
    }
};