// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Tags: Arrays, Dynamic Programming

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX;
        int maxProfit = INT_MIN;

        for(int price: prices){
            minBuy = min(minBuy, price);
            maxProfit = max(maxProfit, price - minBuy);
        }

        return maxProfit;
    }
};