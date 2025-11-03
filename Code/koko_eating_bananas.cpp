// https://leetcode.com/problems/koko-eating-bananas/description/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();

        int l=1;
        int r=*max_element(piles.begin(), piles.end());

        while(l<=r){
            int m=(l+r)/2;

            long hours = 0;

            for(int pile: piles){
                hours += (1l*pile+m-1)/m;
            }

            if(hours>h){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return l;
    }
};