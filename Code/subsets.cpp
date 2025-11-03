// https://leetcode.com/problems/subsets/description/
// Difficulty: Medium
// Tags: Bit Manipulation, Backtracking, Arrays

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<(1<<n); i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int i){
        if(i<0){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        helper(nums, ans, curr, i-1);
        curr.pop_back();
        helper(nums, ans, curr, i-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> curr;
        helper(nums, ans, curr, n-1);
        return ans;
    }
};