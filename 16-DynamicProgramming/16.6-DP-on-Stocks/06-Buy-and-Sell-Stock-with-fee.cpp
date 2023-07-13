/*
Gfg:
Leetcode:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(vector<int> &prices, int idx, int buy, int fee, vector<vector<int>> &dp)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        if (buy)
        {
            int take = helper(prices, idx + 1, 0, fee, dp) - prices[idx];
            int not_take = helper(prices, idx + 1, 1, fee, dp);
            return dp[idx][buy] = max(take, not_take);
        }
        int sell = helper(prices, idx + 1, 1, fee, dp) + prices[idx] - fee;
        int not_sell = helper(prices, idx + 1, 0, fee, dp);
        return dp[idx][buy] = max(sell, not_sell);
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, fee, dp);
    }
};
class tabSolution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[i][buy] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                else
                    dp[i][buy] = max(dp[i + 1][0], dp[i + 1][1] + prices[i] - fee);
            }
        return dp[0][1];
    }
};
class spaceOptimized
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
                if (buy)
                    curr[buy] = max(prev[0] - prices[i], prev[1]);
                else
                    curr[buy] = max(prev[1] + prices[i] - fee, prev[0]);
            prev = curr;
        }
        return prev[1];
    }
};