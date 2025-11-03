// https://leetcode.com/problems/merge-intervals/description/
// Difficulty: Medium
// Tags: Arrays, Sorting

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int idx = 0;

        for(int i=1; i<n; i++){
            if(intervals[idx][1]>=intervals[i][0]){
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            }
            else{
                idx++;
                intervals[idx]=intervals[i];
            }
        }

        intervals.erase(intervals.begin()+idx+1, intervals.end());
        return intervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i<n; i++){
            if(intervals[i][0]<=end){
                end = max(end, intervals[i][1]);
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};