// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        
        int l=0, r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            
            if(arr[m]<=x){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        
        return r;
    }
};
