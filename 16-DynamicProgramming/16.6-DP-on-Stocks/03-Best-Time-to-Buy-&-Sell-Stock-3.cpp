/*
Gfg:
Leetcode:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(vector<int> &prices, int idx, int buy, int maxT, vector<vector<vector<int>>> &dp)
    {
        if (maxT <= 0)
            return 0;
        if (idx >= prices.size())
            return 0;
        if (dp[idx][buy][maxT] != -1)
            return dp[idx][buy][maxT];

        if (buy)
        {
            int take = helper(prices, idx + 1, 0, maxT, dp) - prices[idx];
            int not_take = helper(prices, idx + 1, 1, maxT, dp);
            return dp[idx][buy][maxT] = max(take, not_take);
        }
        int sell = helper(prices, idx + 1, 1, maxT - 1, dp) + prices[idx];
        int not_sell = helper(prices, idx + 1, 0, maxT, dp);
        return dp[idx][buy][maxT] = max(sell, not_sell);
    }
    int maxProfit(vector<int> &prices)

    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, 1, 2, dp);
    }
};
class tabSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--)
            for (int buy = 0; buy <= 1; buy++)
                for (int maxT = 1; maxT <= 2; maxT++)
                    if (buy)
                        dp[idx][buy][maxT] = max(dp[idx + 1][0][maxT] - prices[idx], dp[idx + 1][1][maxT]);
                    else
                        dp[idx][buy][maxT] = max(dp[idx + 1][1][maxT - 1] + prices[idx], dp[idx + 1][0][maxT]);
        return dp[0][1][2];
    }
};
class spaceOptimized
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3, 0)), prev(2, vector<int>(3, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {

            for (int buy = 0; buy <= 1; buy++)
                for (int maxT = 1; maxT <= 2; maxT++)
                    if (buy)
                        curr[buy][maxT] = max(prev[0][maxT] - prices[idx], prev[1][maxT]);
                    else
                        curr[buy][maxT] = max(prev[1][maxT - 1] + prices[idx], prev[0][maxT]);
            prev = curr;
        }
        return prev[1][2];
    }
};
int main()
{
}