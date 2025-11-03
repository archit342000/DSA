// https://www.geeksforgeeks.org/problems/insertion-sort/1
// Difficulty: Easy
// Tags: Sorting, Algorithms, Recursion

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        for(int i=1; i<n; i++){
            int key=arr[i];
            int j=i-1;
            
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            
            arr[j+1] = key;
        }
    }
};


class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int> &arr, int n, int i){
        if(i==n){
            return;
        }
        
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j--];
        }
        
        arr[j+1] = key;
        
        insertionSort(arr, n, i+1);
    }
    void insertionSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        insertionSort(arr, n, 0);
    }
};