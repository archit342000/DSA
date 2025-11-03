// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// Difficulty: Easy
// Tags: Arrays

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxVal=INT_MIN;
        for(int x: arr){
            maxVal=max(maxVal, x);
        }
        return maxVal;
    }
};
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        return *max_element(arr.begin(), arr.end());
    }
};