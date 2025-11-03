// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
// Difficulty: Easy
// Tags: Arrays, Matrices, Binary Search

// User function template for C++
class Solution {
  public:
    int lower_bound(vector<int> &arr, int l, int r){
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]>=1){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();

        int index=0;
        int j=n;
        
        for(int i=0; i<m; i++){
            int curr;
            if(j==n || arr[i][j]==1){
                curr=lower_bound(arr[i], 0, j);
            }
            if(curr<j){
                index=i;
                j=curr;
            }
        }
        
        return index;
    }
};