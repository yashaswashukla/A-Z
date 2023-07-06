/*
Gfg:
Leetcode:https://leetcode.com/problems/coin-change/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (!(amount % coins[idx]))
                return amount / coins[idx];
            return 1e9;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int not_taken = solve(coins, idx - 1, amount, dp), taken = 1e9;
        if (coins[idx] <= amount)
            taken = 1 + solve(coins, idx, amount - coins[idx], dp);
        return dp[idx][amount] = min(not_taken, taken);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
    }
};
class tabSolutio
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int sum = 0; sum <= amount; sum++)
            if (!(sum % coins[0]))
                dp[0][sum] = sum / coins[0];
            else
                dp[0][sum] = 1e9;

        for (int idx = 1; idx < n; idx++)
        {
            for (int sum = 0; sum <= amount; sum++)
            {
                int not_taken = dp[idx - 1][sum], taken = 1e9;
                if (coins[idx] <= sum)
                    taken = 1 + dp[idx][sum - coins[idx]];
                dp[idx][sum] = min(not_taken, taken);
            }
        }
        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }
};
class spaceOptimized
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int sum = 0; sum <= amount; sum++)
            if (!(sum % coins[0]))
                prev[sum] = sum / coins[0];
            else
                prev[sum] = 1e9;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> curr(amount + 1, 0);
            for (int sum = 0; sum <= amount; sum++)
            {
                int not_taken = prev[sum], taken = 1e9;
                if (coins[idx] <= sum)
                    taken = 1 + curr[sum - coins[idx]];
                curr[sum] = min(not_taken, taken);
            }
            prev = curr;
        }
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
int main()
{
}