/*
Gfg:https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (arr[idx] == sum)
                return true;
            return false;
        }
        if (!sum)
            return dp[idx][sum] = true;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool not_taken = solve(arr, idx - 1, sum, dp);
        bool taken = false;
        if (sum >= arr[idx])
            taken = solve(arr, idx - 1, sum - arr[idx], dp);
        return dp[idx][sum] = not_taken or taken;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(101, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum, dp);
    }
};
class tabSolution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int idx = 0; idx < n; idx++)
            dp[idx][0] = 1;
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
            for (int target = 1; target <= sum; target++)
            {
                bool not_taken = dp[idx - 1][target];
                bool taken = false;
                if (target >= arr[idx])
                    taken = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = not_taken or taken;
            }

        return dp[n - 1][sum];
    }
};
class spaceOptimization
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<int> prev(sum + 1, 0);
        prev[0] = 1;
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> row(sum + 1, 0);
            row[0] = 1;
            for (int target = 1; target <= sum; target++)
            {
                bool not_taken = prev[target], taken = false;
                if (arr[idx] <= target)
                    taken = prev[target - arr[idx]];
                row[target] = not_taken or taken;
            }
            prev = row;
        }
        return prev[sum];
    }
};
int main()
{
}