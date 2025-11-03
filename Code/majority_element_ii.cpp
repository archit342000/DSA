// https://leetcode.com/problems/majority-element-ii/
// Difficulty: Medium
// Tags: Arrays, Counting, Algorithms

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el1=INT_MIN, el2=INT_MIN;
        int ct1=0, ct2=0;

        for(int i=0; i<n; i++){
            if(ct1==0 && nums[i]!=el2){
                el1 = nums[i];
                ct1++;
            }
            else if(ct2==0 && nums[i]!=el1){
                el2 = nums[i];
                ct2++;
            }
            else if(nums[i]==el1){
                ct1++;
            }
            else if(nums[i]==el2){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }

        vector<int> ans;
        ct1 = 0;
        ct2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i]==el1){
                ct1++;
            }
            if(nums[i]==el2){
                ct2++;
            }
        }

        if(ct1>n/3){
            ans.push_back(el1);
        }
        if(ct2>n/3){
            ans.push_back(el2);
        }

        return ans;
    }
};