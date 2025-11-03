// https://leetcode.com/problems/majority-element/description/
// Difficult: Easy
// Tags: Arrays, Counting, Algorithms

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int maj_el;
        int count = 0;

        for(int x: nums){
            if(count == 0){
                maj_el = x;
                count++;
            }
            else if(x == maj_el){
                count++;
            }
            else{
                count--;
            }
        }

        count = 0;

        for(int x: nums){
            if(x == maj_el){
                count++;
            }
        }

        if(count>n/2){
            return maj_el;
        }

        return INT_MAX;
    }
};