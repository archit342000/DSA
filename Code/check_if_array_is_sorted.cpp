// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
// Difficulty: Easy
// Tags: Arrays

class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prev=arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i]<prev){
                return false;
            }
            prev=arr[i];
        }
        
        return true;
    }
};