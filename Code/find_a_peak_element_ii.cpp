// https://leetcode.com/problems/find-a-peak-element-ii/description/
// Difficulty: Medium
// Tags: Arrays, Matrices, Binary Search

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int l=0;
        int r=m-1;

        while(l<=r){
            int mid=(l+r)/2;

            int max_idx=0;

            for(int i=1; i<n; i++){
                if(mat[mid][i]>mat[mid][max_idx]){
                    max_idx=i;
                }
            }

            if(((mid>0 && mat[mid][max_idx]>mat[mid-1][max_idx]) || mid==0) && ((mid<m-1 && mat[mid][max_idx]>mat[mid+1][max_idx]) || mid==m-1)){
                return {mid, max_idx};
            }
            else if(mid>0 && mat[mid][max_idx]<mat[mid-1][max_idx]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return {-1, -1};
    }
};