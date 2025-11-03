// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
// Difficulty: Medium
// Tags: Math, Algorithms

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector<int> prime(n+1, 1);
        vector<int> ans;
        prime[0]=prime[1]=0;
        
        for(int i=2; i*i<=n; i++){
            if(prime[i]==1){
                for(int j=i*i; j<=n; j+=i){
                    prime[j]=0;
                }
            }
        }
        
        int i=2; 
        while(n>1){
            if(n%i==0){
                if(prime[i]==1){
                    ans.push_back(i);
                }
                n/=i;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};