/*
Gfg:https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
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
        if (arr[idx] <= sum)
            taken = solve(arr, idx - 1, sum - arr[idx], dp);
        return dp[idx][sum] = (not_taken + taken) % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum = sum - d;
        if (sum % 2)
            return 0;
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, n - 1, target, dp);
    }
};
class tabSolution
{
public:
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum = sum - d;
        if (sum < 0 or sum % 2)
            return 0;
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        if (!arr[0])
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (arr[0])
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int curr = 0; curr <= target; curr++)
            {
                int not_taken = dp[idx - 1][curr], taken = 0;
                if (arr[idx] <= curr)
                    taken = dp[idx - 1][curr - arr[idx]];
                dp[idx][curr] = (taken + not_taken) % mod;
            }
        }
        return dp[n - 1][target];
    }
};
class spaceOptimization
{
public:
    int mod = 1e9 + 7;
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum = sum - d;
        if (sum < 0 or sum % 2)
            return 0;
        int target = sum / 2;
        vector<int> prev(target + 1, 0);
        if (!arr[0])
            prev[0] = 2;
        else
            prev[0] = 1;
        if (arr[0] <= target and arr[0])
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> row(target + 1, 0);
            for (int curr = 0; curr <= target; curr++)
            {
                int not_taken = prev[curr], taken = 0;
                if (arr[idx] <= curr)
                    taken = prev[curr - arr[idx]];
                row[curr] = (taken + not_taken) % mod;
            }
            prev = row;
        }

        return prev[target];
    }
};
int main()
{
}