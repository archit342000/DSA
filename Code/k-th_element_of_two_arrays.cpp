// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Difficulty: Hard
// Tags: Arrays, Binary Search, Divide and Conquer

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m=a.size();
        int n=b.size();
        
        if(m>n){
            return kthElement(b, a, k);
        }
        
        int l=max(0, k-n);
        int r=min(k, m);
        
        while(l<=r){
            int m1=(l+r)/2;
            int m2=k-m1;
            
            int l1=(m1>0)?a[m1-1]:INT_MIN;
            int l2=(m2>0)?b[m2-1]:INT_MIN;
            int r1=(m1<m)?a[m1]:INT_MAX;
            int r2=(m2<n)?b[m2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1){
                return max(l1, l2);
            }
            else if(l1>r2){
                r=m1-1;
            }
            else{
                l=m1+1;
            }
        }
        
        return -1;
    }
};