// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Difficulty: Hard
// Tags: Arrays, Binary Search, Divide and Conquer

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1>n2){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n=n1+n2;
        int l_len=(n+1)/2;
        int l=0;
        int r=n1;

        while(l<=r){
            int m1=(l+r)/2;
            int m2=l_len-m1;

            int l1=INT_MIN, r1=INT_MAX;
            int l2=INT_MIN, r2=INT_MAX;

            if(m1>0){
                l1=nums1[m1-1];
            }
            if(m2>0){
                l2=nums2[m2-1];
            }
            if(m1<n1){
                r1=nums1[m1];
            }
            if(m2<n2){
                r2=nums2[m2];
            }

            if(l1<=r2 && l2<=r1){
                if(n%2){
                    return max(l1, l2);
                }
                else{
                    return (max(l1, l2)+min(r1, r2))/2.0;
                }
            }
            else if(l1>r2){
                r=m1-1;
            }
            else{
                l=m1+1;
            }
        }

        return 0;
    }
};
