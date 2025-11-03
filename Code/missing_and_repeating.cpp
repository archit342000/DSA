// https://leetcode.com/problems/find-missing-and-repeated-values/description/
// Difficulty: Medium
// Tags: Arrays, Bit Manipulation

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int xr = 0;
        
        for(int i=0; i<n; i++){
            xr = xr ^ arr[i];
            xr = xr ^ (i+1);
        }
        
        int diff = xr & ~(xr-1);
        
        int one = 0, zero = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i]&diff){
                one = one ^ arr[i];
            }
            else{
                zero = zero ^ arr[i];
            }
            
            if((i+1)&diff){
                one = one ^ (i+1);
            }
            else{
                zero = zero ^ (i+1);
            }
        }
        
        int count=0;
        
        for(int i=0; i<n; i++){
            if(zero == arr[i]){
                count++;
            }
        }
        
        if(count == 2){
            return {zero, one};
        }
        return {one, zero};
    }
};