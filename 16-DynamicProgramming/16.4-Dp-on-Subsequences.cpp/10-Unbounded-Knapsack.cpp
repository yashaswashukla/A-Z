/*
Gfg:https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &profit, vector<int> &weight, int idx, int target, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (target < weight[idx])
                return 0;
            int amount = target / weight[idx];
            return profit[idx] * amount;
        }
        if (target <= 0)
            return 0;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int not_taken = solve(profit, weight, idx - 1, target, dp), taken = -1;
        if (weight[idx] <= target)
            taken = solve(profit, weight, idx, target - weight[idx], dp) + profit[idx];
        dp[idx][target] = max(not_taken, taken);
    }
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return solve(profit, weight, n - 1, w, dp);
    }
};
class tabSolution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));
        for (int target = 0; target <= w; target++)
        {
            int amount = target / weight[0];
            dp[0][target] = amount * profit[0];
        }
        for (int idx = 0; idx < n; idx++)
            dp[idx][0] = 0;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= w; target++)
            {
                int not_taken = dp[idx - 1][target], taken = 0;
                if (weight[idx] <= target)
                    taken = dp[idx][target - weight[idx]] + profit[idx];
                dp[idx][target] = max(not_taken, taken);
            }
        }
        return dp[n - 1][w];
    }
};
class spaceOptimized
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<int> prev(w + 1, 0), curr(w + 1, 0);

        for (int target = 0; target <= w; target++)
        {
            int amount = target / weight[0];
            prev[target] = amount * profit[0];
        }

        for (int idx = 1; idx < n; idx++)
        {
            curr[0] = 0;
            for (int target = 1; target <= w; target++)
            {
                int not_taken = prev[target], taken = 0;
                if (weight[idx] <= target)
                    taken = curr[target - weight[idx]] + profit[idx];
                curr[target] = max(not_taken, taken);
            }
            prev = curr;
        }
        return prev[w];
    }
};
int main()
{
}