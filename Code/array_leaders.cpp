// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Difficulty: Easy
// Tags: Arrays

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int maxRight = arr.back();

        for(auto it=arr.rbegin(); it<arr.rend(); it++){
            if(*it>=maxRight){
                ans.push_back(*it);
                maxRight = *it;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};