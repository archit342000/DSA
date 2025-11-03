// https://www.geeksforgeeks.org/problems/implement-upper-bound/1
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        int l=0, r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            
            if(arr[m]>target){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return l;
    }
};
