// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Difficulty: Medium
// Tags: Arrays, Binary Search

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        if(1ll*m * 1ll*k > n){
            return -1;
        }

        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int r=*max_element(bloomDay.begin(), bloomDay.end());

        while(l<=r){
            int mid=(l+r)/2;

            int f_c=0, b_c=0;

            for(int day: bloomDay){
                if(day<=mid){
                    f_c++;
                }
                else{
                    f_c = 0;
                }

                if(f_c==k){
                    b_c++;
                    f_c=0;
                }
                if(b_c>m){
                    break;
                }
            }

            if(b_c>=m){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }
};