// https://www.geeksforgeeks.org/problems/odd-or-even3618/1
// Difficulty: Easy
// Tags: Bit Manipulation

class Solution {
  public:
    bool isEven(int n) {
        // code here
        return !(n&1);
    }
};