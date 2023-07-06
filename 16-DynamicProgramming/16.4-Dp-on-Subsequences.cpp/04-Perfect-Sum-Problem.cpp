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
            return sum == arr[idx];
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
        return solve(arr, n - 1, sum, dp);
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
        if (arr[0])
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= sum; target++)
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
class spaceOptimized
{
public:
    int mod = 1e9 + 7;
    int perfectSum(int arr[], int n, int sum)
    {
        vector<int> prev(sum + 1, 0);
        if (!arr[0])
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0])
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> curr(sum + 1, 0);
            for (int currsum = 0; currsum <= sum; currsum++)
            {
                int not_taken = prev[currsum], taken = 0;
                if (arr[idx] <= currsum)
                    taken = prev[currsum - arr[idx]];
                curr[currsum] = (not_taken + taken) % mod;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
int main()
{
}