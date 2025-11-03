// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        int l=*max_element(arr.begin(), arr.end());
        int r=accumulate(arr.begin(), arr.end(), 0);
        
        while(l<=r){
            int m=(l+r)/2;
            
            int c=0;
            int t=0;
            
            for(int x: arr){
                if(t+x>m){
                    c++;
                    t=0;
                }
                t+=x;
            }
            
            if(t>0){
                c++;
            }
            
            if(c<=k){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return l;
    }
};