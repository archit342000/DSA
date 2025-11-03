// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
// Difficulty: Easy
// Tags: Bit Manipulation

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        return (n&(1<<k));
    }
};