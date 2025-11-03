// https://www.geeksforgeeks.org/problems/set-bits0143/1
// Difficulty: Easy
// Tags: Bit Manipulation

class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        for(int i=0; i<=31; i++){
            if(n&(1<<i)){
                count++;
            }
        }
        return count;
    }
};