// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Difficulty: Medium
// Tags: Arrays, Divide and Conquer, Sorting, Algorithms

class Solution {
  public:
    int merge(vector<int> &arr, int left, int mid, int right){
        int n_left = mid-left+1;
        int n_right = right-mid;
        
        vector<int> arr_left(n_left);
        vector<int> arr_right(n_right);
        
        for(int i=0; i<n_left; i++){
            arr_left[i] = arr[i+left];
        }
        
        for(int i=0; i<n_right; i++){
            arr_right[i] = arr[i+mid+1];
        }
        
        int count = 0;
        
        int i=0, j=0, k=left;
        
        while(i<n_left && j<n_right){
            if(arr_left[i]<=arr_right[j]){
                arr[k++] = arr_left[i++];
            }
            else{
                count += (n_left-i);
                arr[k++] = arr_right[j++];
            }
        }
        
        while(i<n_left){
            arr[k++] = arr_left[i++];
        }
        
        while(j<n_right){
            arr[k++] = arr_right[j++];
        }
        
        return count;
    }
    int mergeSort(vector<int> &arr, int left, int right){
        int count=0;
        if(left<right){
            int mid = (left+right)/2;
            
            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid+1, right);
            count += merge(arr, left, mid, right);
        }
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        return mergeSort(arr, 0, n-1);
        
    }
};