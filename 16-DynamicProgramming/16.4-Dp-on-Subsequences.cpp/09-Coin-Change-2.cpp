/*
Gfg:https://practice.geeksforgeeks.org/problems/coin-change2448/1
Leetcode:https://leetcode.com/problems/coin-change-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(int coins[], int idx, int sum, vector<vector<long long>> &dp)
    {
        if (!idx)
            return !(sum % coins[idx]);
        if (!sum)
            return 1;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        long long not_taken = solve(coins, idx - 1, sum, dp), taken = 0;
        if (coins[idx] <= sum)
            taken = solve(coins, idx - 1, sum - coins[idx], dp);
        return dp[idx][sum] = not_taken + taken;
    }
    long long int count(int coins[], int N, int sum)
    {
        vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
        return solve(coins, N - 1, sum, dp);
    }
};
class tabSolution
{
public:
    long long int count(int coins[], int n, int sum)
    {
        vector<vector<long long>> dp(n, vector<long long>(sum + 1, 0));
        for (int idx = 0; idx < n; idx++)
            dp[idx][0] = 1;
        for (int curr = coins[0]; curr <= sum; curr++)
            if (!(curr % coins[0]))
                dp[0][curr] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int curr = 1; curr <= sum; curr++)
            {
                long long not_taken = dp[idx - 1][curr], taken = 0;
                if (curr >= coins[idx])
                    taken = dp[idx][curr - coins[idx]];
                dp[idx][curr] = not_taken + taken;
            }
        }
        return dp[n - 1][sum];
    }
};
class spaceOptimized
{
public:
    long long int count(int coins[], int n, int sum)
    {
        vector<long long> prev(sum + 1, 0), curr(sum + 1);
        for (int curr = 0; curr <= sum; curr++)
            if (!(curr % coins[0]))
                prev[curr] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            curr[0] = 1;
            for (int currsum = 1; currsum <= sum; currsum++)
            {
                long long not_taken = prev[currsum], taken = 0;
                if (coins[idx] <= currsum)
                    taken = curr[currsum - coins[idx]];
                curr[currsum] = not_taken + taken;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
int main()
{
}