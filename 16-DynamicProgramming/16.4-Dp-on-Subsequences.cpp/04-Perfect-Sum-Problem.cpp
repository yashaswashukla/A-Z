/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int arr[], int idx, int sum, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (!sum and !arr[idx])
                return 2;
            if (!sum)
                return 1;
            return arr[idx] == sum;
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int not_taken = solve(arr, idx - 1, sum, dp), taken = 0;

        if (sum >= arr[idx])
            taken = solve(arr, idx - 1, sum - arr[idx], dp);

        return dp[idx][sum] = (not_taken + taken) % mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum, dp) % mod;
    }
};
class tabSolution
{
public:
    int mod = 1e9 + 7;
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        if (!arr[0])
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                int not_taken = dp[idx - 1][target], taken = 0;
                if (arr[idx] <= target)
                    taken = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = (not_taken + taken) % mod;
            }
        }
        return dp[n - 1][sum];
    }
};
int main()
{
}