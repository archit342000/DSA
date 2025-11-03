// https://leetcode.com/problems/sort-colors/description/
// Difficulty: Easy
// Tags: Array

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);

        for(int x: nums){
            freq[x]++;
        }

        int i=0;
        for(int j=0; j<3; j++){
            for(int k=0; k<freq[j]; k++){
                nums[i++] = j;
            }
        }
    }
};