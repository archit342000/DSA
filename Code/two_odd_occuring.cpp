// https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
// Difficulty: Medium
// Tags: Bit Manipulation

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int xr=0;
        
        for(int x: arr){
            xr=xr^x;
        }
        
        int diff=xr&~(xr-1);
        
        int xr2=0;
        
        for(int x: arr){
            if(x&diff){
                xr2=xr2^x;
            }
        }
        
        xr=xr^xr2;
        
        if(xr>xr2){
            return {xr, xr2};
        }
        return {xr2, xr};
    }
};