// https://leetcode.com/problems/reverse-pairs/description/
// Difficulty: Hard
// Tags: Arrays, Divide and Conquer, Sorting, Algorithms

class Solution {
public:
    void merge(vector<int> &nums, int l, int m, int r){
        int n_l = m-l+1;
        int n_r = r-m;

        vector<int> left(n_l);
        vector<int> right(n_r);

        for(int i=0; i<n_l; i++){
            left[i] = nums[i+l];
        }

        for(int i=0; i<n_r; i++){
            right[i] = nums[i+m+1];
        }

        int i=0, j=0, k=l;

        while(i<n_l && j<n_r){
            if(left[i]<=right[j]){
                nums[k++] = left[i++];
            }
            else{
                nums[k++] = right[j++];
            }
        }

        while(i<n_l){
            nums[k++] = left[i++];
        }

        while(j<n_r){
            nums[k++] = right[j++];
        }
    }
    int countPairs(vector<int> &nums, int l, int m, int r){
        int count = 0;
        int left_i = l;
        int right_i = m+1;

        while(left_i<=m){
            while(right_i<=r && nums[left_i]>2ll*nums[right_i]){
                right_i++;
            }
            count += (right_i-m-1);
            left_i++;
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int l, int r){
        int count = 0;

        if(l<r){
            int m = (l+r)/2;

            count += mergeSort(nums, l, m);
            count += mergeSort(nums, m+1, r);
            count += countPairs(nums, l, m, r);
            merge(nums, l, m, r);
        }

        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return mergeSort(nums, 0, n-1);
    }
};