/*
Gfg:https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int wt[], int val[], int idx, int W, vector<vector<int>> &dp)
    {
        if (W <= 0)
            return 0;
        if (!idx)
        {
            if (W >= wt[idx])
                return val[idx];
            return 0;
        }

        if (dp[idx][W] != -1)
            return dp[idx][W];

        int not_taken = helper(wt, val, idx - 1, W, dp), taken = -1;
        if (wt[idx] <= W)
            taken = helper(wt, val, idx - 1, W - wt[idx], dp) + val[idx];

        return dp[idx][W] = max(taken, not_taken);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return helper(wt, val, n - 1, W, dp);
    }
};
class tabSolution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int curr = wt[0]; curr <= W; curr++)
            dp[0][curr] = val[0];

        for (int idx = 1; idx < n; idx++)
        {
            for (int weight = 0; weight <= W; weight++)
            {
                int not_taken = dp[idx - 1][weight], taken = -1;
                if (wt[idx] <= weight)
                    taken = dp[idx - 1][weight - wt[idx]] + val[idx];
                dp[idx][weight] = max(not_taken, taken);
            }
        }
        return dp[n - 1][W];
    }
};
class spaceOptimized
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<int> dp(W + 1, 0);
        for (int weight = wt[0]; weight <= W; weight++)
            dp[weight] = val[0];

        for (int idx = 1; idx < n; idx++)
            for (int weight = W; weight >= 0; weight--)
            {
                int not_taken = dp[weight], taken = -1;
                if (wt[idx] <= weight)
                    taken = dp[weight - wt[idx]] + val[idx];
                dp[weight] = max(not_taken, taken);
            }
        return dp[W];
    }
};
int main()
{
}