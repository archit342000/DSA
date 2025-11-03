// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1
// Difficulty: Easy
// Tags: Math

// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int n2=n;
        int sum=0;
        while(n>0){
            int d=n%10;
            n/=10;
            sum+=(d*d*d);
        }
        return sum==n2;
    }
};
