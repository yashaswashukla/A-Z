/*
Gfg:
Leetcode:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        if (buy)
        {
            int take = helper(prices, idx + 1, 0, dp) - prices[idx];
            int not_take = helper(prices, idx + 1, 1, dp);
            return dp[idx][buy] = max(take, not_take);
        }
        int sell = helper(prices, idx + 2, 1, dp) + prices[idx];
        int not_sell = helper(prices, idx + 1, 0, dp);
        return dp[idx][buy] = max(sell, not_sell);
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};
class tabSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[i][buy] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                else
                    dp[i][buy] = max(dp[i + 1][0], dp[i + 2][1] + prices[i]);
            }
        return dp[0][1];
    }
};
class spaceOptimized
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0), twoback(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
                if (buy)
                    curr[buy] = max(prev[0] - prices[i], prev[1]);
                else
                    curr[buy] = max(twoback[1] + prices[i], prev[0]);
            twoback = prev;
            prev = curr;
        }
        return prev[1];
    }
};