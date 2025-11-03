// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
// Difficulty: Easy
// Tags: Arrays, Binary Search

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        
        int l=0, r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            
            if(arr[m]>=x){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return l<n?l:-1;
    }
};