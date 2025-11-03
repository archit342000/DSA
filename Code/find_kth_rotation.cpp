// https://www.geeksforgeeks.org/problems/rotation4723/1
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        
        int l=0, r=n-1;
        
        while(l<=r){
            int m=(l+r)/2;
            
            if(arr[l]<=arr[r]){
                break;
            }
            
            if(arr[l]<=arr[m]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        
        return l;
    }
};
