// https://www.geeksforgeeks.org/problems/quick-sort/1
// Difficulty: Medium
// Tags: Sorting, Algorithms, Divide and Conquer, Recursion

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int p = partition(arr, low, high);
            quickSort(arr, low, p-1);
            quickSort(arr, p+1, high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int i = low + rand() % (high-low+1);
        swap(arr[i], arr[high]);
        
        i = low-1;
        
        for(int j=low; j<high; j++){
            if(arr[j]<arr[high]){
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[++i], arr[high]);
        return i;
    }
};