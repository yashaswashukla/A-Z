/*
Gfg:https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int price[], int idx, int n, vector<vector<int>> &dp)
    {
        if (!idx)
            return n * price[0];
        if (!n)
            return 0;
        if (dp[idx][n] != -1)
            return dp[idx][n];
        int not_cut = solve(price, idx - 1, n, dp), cut = 0;
        if (n >= idx + 1)
            cut = price[idx] + solve(price, idx, n - idx - 1, dp);
        return dp[idx][n] = max(not_cut, cut);
    }
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(price, n - 1, n, dp);
    }
};
class tabSolution
{
public:
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int len = 0; len <= n; len++)
            dp[0][len] = len * price[0];

        for (int idx = 1; idx < n; idx++)
            for (int len = 1; len <= n; len++)
            {
                int not_cut = dp[idx - 1][len], cut = 0;
                if (idx + 1 <= len)
                    cut = dp[idx][len - idx - 1] + price[idx];
                dp[idx][len] = max(not_cut, cut);
            }

        return dp[n - 1][n];
    }
};
class spaceOptimized
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int len = 0; len <= n; len++)
            prev[len] = len * price[0];

        for (int idx = 1; idx < n; idx++)
        {
            for (int len = 1; len <= n; len++)
            {
                int not_cut = prev[len], cut = 0;
                if (idx + 1 <= len)
                    cut = curr[len - idx - 1] + price[idx];
                curr[len] = max(not_cut, cut);
            }
            prev = curr;
        }
        return prev[n];
    }
};
int main()
{
}