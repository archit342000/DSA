// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Difficulty: Easy
// Tags: Arrays, Binary Search

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int first=-1, last=-1;
        
        int left=0;
        int right=n-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            if(arr[mid]==target){
                first=mid;
            }
            
            if(arr[mid]>=target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        left=0;
        right=n-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            if(arr[mid]==target){
                last=mid;
            }
            
            if(arr[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        
        if(first==-1){
            return 0;
        }
        return last-first+1;
    }
};