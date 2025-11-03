// https://www.geeksforgeeks.org/problems/reverse-an-array/1
// Difficulty: Easy
// Tags: Arrays, Two Pointers, Recursion

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n/2; i++){
            arr[i]=arr[i]^arr[n-1-i];
            arr[n-1-i]=arr[i]^arr[n-1-i];
            arr[i]=arr[i]^arr[n-1-i];
        }
    }
};


class Solution {
  public:
    void reverseArrayHelper(vector<int> &arr, int n, int i){
        if(i>=n/2){
            return;
        }
        arr[i] = arr[i] ^ arr[n-1-i];
        arr[n-1-i] = arr[i] ^ arr[n-1-i];
        arr[i] = arr[i] ^ arr[n-1-i];
        reverseArrayHelper(arr, n, i+1);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        reverseArrayHelper(arr, n, 0);
    }
};
