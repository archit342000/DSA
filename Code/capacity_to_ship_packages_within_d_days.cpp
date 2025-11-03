// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int l=*max_element(weights.begin(), weights.end());
        int r=accumulate(weights.begin(), weights.end(), 0);

        while(l<=r){
            int m=(l+r)/2;

            int wt_sum=0;
            int c=0;

            for(int wt: weights){
                if(wt_sum+wt>m){
                    c++;
                    wt_sum=wt;
                }
                else{
                    wt_sum+=wt;
                }

                if(c>days){
                    break;
                }
            }

            if(wt_sum>0){
                c++;
            }

            if(c<=days){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return l;
    }
};