// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n){
            return -1;
        }
        
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        
        while(l<=r){
            int m = (l+r)/2;
            
            int count=0;
            int pages=0;
            
            for(int x: arr){
                if(pages+x > m){
                    count++;
                    pages=0;
                }
                pages+=x;
            }
            if(pages>0){
                count++;
            }
            
            if(count<=k){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return l;
    }
};