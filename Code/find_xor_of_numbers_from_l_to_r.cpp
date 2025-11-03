// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
// Difficulty: Easy
// Tags: Bit Manipulation

// User function Template for C++

class Solution {
  public:
    int XORtoN(int n){
        if(n%4==1){
            return 1;
        }
        if(n%4==2){
            return n+1;
        }
        if(n%4==3){
            return 0;
        }
        return n;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return XORtoN(l-1)^XORtoN(r);
    }
};