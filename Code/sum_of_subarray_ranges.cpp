// https://leetcode.com/problems/sum-of-subarray-ranges/description/
// Difficulty: Medium
// Tags: Arrays, Stacks, Monotonic Stacks

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        vector<long long int> mins(n);
        vector<long long int> maxs(n);

        long long int ans=0;

        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[st1.top()]>=nums[i]){
                st1.pop();
            }
            int j=-1;
            if(!st1.empty()){
                j=st1.top();
            }
            if(j==-1){
                mins[i]=nums[i]*1ll*(i+1);
            }
            else{
                mins[i]=mins[j]+nums[i]*1ll*(i-j);
            }
            st1.push(i);

            while(!st2.empty() && nums[st2.top()]<=nums[i]){
                st2.pop();
            }

            j=-1;
            if(!st2.empty()){
                j=st2.top();
            }
            if(j==-1){
                maxs[i]=nums[i]*1ll*(i+1);
            }
            else{
                maxs[i]=maxs[j]+nums[i]*1ll*(i-j);
            }
            st2.push(i);
        }

        for(int i=0; i<n; i++){
            ans = (ans + (maxs[i]-mins[i]));
        }

        return ans;
    }
};

