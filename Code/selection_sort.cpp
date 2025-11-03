// https://www.geeksforgeeks.org/problems/selection-sort/1
// Difficulty: Easy
// Tags: Sorting, Algorithms

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0; i<n-1; i++){
            int min_i=i;
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[min_i]){
                    min_i=j;
                }
            }
            swap(arr[i], arr[min_i]);
        }
    }
};

