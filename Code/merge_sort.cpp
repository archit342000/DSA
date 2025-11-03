// https://www.geeksforgeeks.org/problems/merge-sort/1
// Difficulty: Medium
// Tags: Sorting, Algorithms, Divide and Conquer, Recursion

class Solution {
  public:
    void merge(vector<int> &arr, int l, int mid, int r){
        int n_left = mid-l+1;
        int n_right = r-mid;
        
        vector<int> temp_left(n_left);
        vector<int> temp_right(n_right);
        
        for(int i=0; i<n_left; i++){
            temp_left[i] = arr[i+l];
        }
        
        for(int j=0; j<n_right; j++){
            temp_right[j] = arr[j+mid+1];
        }
        
        int i=0, j=0, k=l;
        
        while(i<n_left && j<n_right){
            if(temp_left[i]<=temp_right[j]){
                arr[k++] = temp_left[i++];
            }
            else{
                arr[k++] = temp_right[j++];
            }
        }
        
        while(i<n_left){
            arr[k++] = temp_left[i++];
        }
        
        while(j<n_right){
            arr[k++] = temp_right[j++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l<r){
            int mid = (l+r)/2;
            
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            
            merge(arr, l, mid, r);
        }
    }
};