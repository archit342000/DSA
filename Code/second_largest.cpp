// https://www.geeksforgeeks.org/problems/second-largest3735/1
// Difficulty: Easy
// Tags: Array

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int max1=-1;
        int max2=-1;
        
        for(int i=0; i<n; i++){
            if(arr[i]>max1){
                max2=max1;
                max1=arr[i];
            }
            else if(arr[i]>max2 && arr[i]!=max1){
                max2=arr[i];
            }
        }
        
        return max2;
    }
};