// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Difficulty: Easy
// Tags: Array, Two Pointers

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> ans;
        int n1=a.size();
        int n2=b.size();
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                if(ans.empty() || (ans.back()!=a[i])){
                    ans.push_back(a[i]);
                }
                i++;
            }
            else{
                if(ans.empty() || (ans.back()!=b[j])){
                    ans.push_back(b[j]);
                }
                j++;
            }
            
        }
        
        while(i<n1){
                if(ans.back()!=a[i]){
                    ans.push_back(a[i]);
                }
                i++;
            }
            
        while(j<n2){
            if(ans.back()!=b[j]){
                ans.push_back(b[j]);
            }
            j++;
        }
            
        return ans;    
    }
};