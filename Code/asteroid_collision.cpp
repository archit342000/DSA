// https://leetcode.com/problems/asteroid-collision/description/
// Difficulty: Medium
// Tags: Arrays, Stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int> ans;

        for(int x: asteroids){
            if(x>0){
                ans.push_back(x);
            }
            else{
                while(!ans.empty() && ans.back()>0 && ans.back()<-x){
                    ans.pop_back();
                }

                if(!ans.empty() && ans.back()==-x){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back()<0){
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};