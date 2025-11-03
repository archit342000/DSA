// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// Difficulty: Medium
// Tags: Arrays, Binary Search, Math

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        long long left=0;
        long long right=ceil(m/n);
        
        while(left<=right){
            long long mid = (left+right)/2;
            
            long long val=1;
            
            for(int i=0; i<n; i++){
                val=val*mid;
                
                if(val>m){
                    right=mid-1;
                    break;
                }
            }
            
            if(val==m){
                return mid;
            }
            if(val<m){
                left=mid+1;
            }
        }
        
        return -1;
    }
};