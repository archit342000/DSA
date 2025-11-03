// https://www.geeksforgeeks.org/problems/prime-factors5052/1
// Difficulty: Easy
// Tags: Math

class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> ans;
        
        if(n%2==0){
            ans.push_back(2);
        }
        
        while(n%2==0){
            n/=2;
        }
        
        for(int i=3; i*i<=n; i+=2){
            if(n%i==0){
                ans.push_back(i);
            }
            while(n%i==0){
                n/=i;
            }
        }
        
        if(n!=1){
            ans.push_back(n);
        }
        
        return ans;
    }
};

