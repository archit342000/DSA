// https://www.geeksforgeeks.org/problems/count-digits-1606889545/1
// Difficulty: Easy
// Tags: Mathematical

class Solution {
  public:
    int countDigits(int n) {
        // code here
        int c=0;
        
        while(n>0){
            n/=10;
            c++;
        }
        
        return c;
    }
};
