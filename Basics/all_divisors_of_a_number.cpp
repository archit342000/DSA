// https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
// Difficulty: Easy


class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> ans1;
        vector<int> ans2;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                ans1.push_back(i);
                int q=n/i;
                if(q!=i){
                    ans2.push_back(q);
                }
            }
        }
        
        for(int i=0; i<ans1.size(); i++){
            cout << ans1[i] << " ";
        }
        for(int i=ans2.size()-1; i>=0; i--){
            cout << ans2[i] << " ";
        }
    }
};
