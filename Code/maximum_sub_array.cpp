// https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1
// Difficulty: Medium 
// Tags: Array, Algorithms, Two Pointers

// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int start=-1;
        int end=-1;
        int curr_start=0;
        int sum=0;
        int max_sum=-1;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==max_sum && start==curr_start){
                end=i;
            }
            if(sum>max_sum){
                start=curr_start;
                end=i;
                max_sum=sum;
            }
            if(arr[i]<0){
                sum=0;
                curr_start=i+1;
            }
        }
        
        if(max_sum==-1){
            return {-1};
        }
        
        vector<int> ans;
        for(int i=start; i<=end; i++){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};