// https://www.geeksforgeeks.org/problems/prime-number2314/1
// Difficulty: Easy
// Tags: Mathematical

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1){
            return false;
        }
        if(n%2==0 && n!=2){
            return false;
        }
        
        
        for(int i=2; i<n; i++){
            if(n%i==0){
                return false;
            }
        }
        
        return true;
    }
};
