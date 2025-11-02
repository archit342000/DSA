// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
// Difficulty: Easy
// Tags: Mathematical, Recursion

class Solution {
  public:
    
    int gcd(int a, int b) {
        // code here
        if(b>a){
            gcd(b, a);
        }
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
};


class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else if(b>a){
                b=b%a;
            }
            else{
                break;
            }
        }
        if(a==0){
            return b;
        }
        else if(b==0){
            return a;
        }
        else{
            return a;
        }
    }
};



class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        while(a>0 && b>0){
            if(a>b){
                a=a-b;
            }
            else if(b>a){
                b=b-a;
            }
            else{
                break;
            }
        }
        if(a==0){
            return b;
        }
        else if(b==0){
            return a;
        }
        else{
            return a;
        }
    }
};
