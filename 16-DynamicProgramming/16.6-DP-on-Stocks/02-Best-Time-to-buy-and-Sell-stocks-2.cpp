/*
Gfg:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Leetcode:https://practice.geeksforgeeks.org/problems/buy-stock-2/1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long helper(vector<long long> &prices, int idx, int buy, vector<vector<long long>> &dp)
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
        int sell = prices[idx] + helper(prices, idx + 1, 1, dp);
        int not_sell = helper(prices, idx + 1, 0, dp);
        return dp[idx][buy] = max(sell, not_sell);
    }
    long long maximumProfit(vector<long long> &prices, int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(prices, 0, 1, dp);
    }
};
class tabSolution
{
public:
    long long maximumProfit(vector<long long> &prices, int n)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                    dp[i][buy] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                else
                    dp[i][buy] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
            }
        return dp[0][1];
    }
};
class spaceOptimized
{
public:
    long long maximumProfit(vector<long long> &prices, int n)
    {
        vector<long long> prev(2, 0), curr(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
                if (buy)
                    curr[buy] = max(prev[0] - prices[i], prev[1]);
                else
                    curr[buy] = max(prev[1] + prices[i], prev[0]);
            prev = curr;
        }
        return prev[1];
    }
};
int main()
{
}