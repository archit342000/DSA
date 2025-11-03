// https://leetcode.com/problems/set-matrix-zeroes/description/
// Difficulty: Medium
// Tags: Arrays, Matrix, Hashing

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        bool rowFlag=false, colFlag=false;

        for(int i=0; i<row; i++){
            if(matrix[i][0]==0){
                colFlag=true;
                break;
            }
        }

        for(int j=0; j<col; j++){
            if(matrix[0][j]==0){
                rowFlag=true;
                break;
            }
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(colFlag){
            for(int i=0; i<row; i++){
                matrix[i][0]=0;
            }
        }

        if(rowFlag){
            for(int j=0; j<col; j++){
                matrix[0][j]=0;
            }
        }
    }
};