// https://leetcode.com/problems/trapping-rain-water/description/
// Difficulty: Hard
// Tags: Arrays, Two Pointers, Stacks, Monotonic Stacks, Dynamic Programming

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=INT_MIN;
        int rightMax=INT_MIN;
        int n=height.size();
        int ans=0;
        int l=0;
        int r=n-1;

        while(l<=r){
            if(leftMax<rightMax){
                leftMax=max(leftMax, height[l]);
                ans = ans + (leftMax-height[l]);
                l++;
            }
            else{
                rightMax=max(rightMax, height[r]);
                ans = ans + (rightMax-height[r]);
                r--;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int water=0;

        left[0]=height[0];
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }

        right[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        for(int i=1; i<n-1; i++){
            int minHeight = min(left[i-1], right[i+1]);
            if(minHeight>height[i]){
                water += (minHeight-height[i]);
            }
        }

        return water;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int ans=0;

        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int curr=height[st.top()];
                st.pop();
                if(st.empty()){
                    break;
                }
                int width=i-st.top()-1;
                ans = ans + (min(height[st.top()], height[i])-curr)*width;
            }
            st.push(i);
        }

        return ans;
    }
};

