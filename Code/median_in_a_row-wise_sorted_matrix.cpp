// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Difficulty: Hard
// Tags: Arrays, Matrix, Binary Search

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        
        int l=INT_MAX;
        int r=INT_MIN;
        
        for(int i=0; i<m; i++){
            l=min(l, mat[i][0]);
            r=max(r, mat[i][n-1]);
        }
        
        while(l<r){
            int mid=(l+r)/2;
            
            int less_or_equal = 0;
            
            for(int i=0; i<m; i++){
                less_or_equal += (upper_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin());
            }
            
            if(less_or_equal >= (m*n+1)/2){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        return r;
    }
};
