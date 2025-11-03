// https://www.geeksforgeeks.org/problems/bubble-sort/1
// Difficulty: Easy
// Tags: Sorting, Algorithms, Recursion

class Solution {
  public:
    void helper2(vector<int> &arr, int i, int j){
        if(j<0){
            return;
        }
        
        helper2(arr, i, j-1);
        
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
  
    void helper1(vector<int> &arr, int i, int n){
        if(i<0){
            return;
        }
        
        helper1(arr, i-1, n);
        
        helper2(arr, i, n-2-i);
    }
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        helper1(arr, n-2, n);
    }
};

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};