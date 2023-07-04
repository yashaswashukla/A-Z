/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool solve(int arr[], int idx, int target, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (target == arr[idx])
                return true;
            return false;
        }

        if (!target)
            return dp[idx][target] = 1;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int not_taken = solve(arr, idx - 1, target, dp), taken = false;
        if (arr[idx] <= target)
            taken = solve(arr, idx - 1, target - arr[idx], dp);
        return dp[idx][target] = not_taken or taken;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalsum = accumulate(arr, arr + N, 0);
        if (totalsum % 2)
            return false;
        vector<vector<int>> dp(N, vector<int>(totalsum / 2 + 1, -1));
        return solve(arr, N - 1, totalsum / 2, dp);
    }
};
class tabSolution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr + N, 0);
        if (sum % 2)
            return false;

        vector<vector<int>> dp(N, vector<int>(sum / 2 + 1, 0));
        for (int idx = 0; idx < N; idx++)
            dp[idx][0] = 1;
        sum = sum / 2;
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < N; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool nt = dp[idx - 1][target], taken = false;
                if (arr[idx] <= target)
                    taken = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = nt or taken;
            }
        }
        return dp[N - 1][sum];
    }
};
class spaceOptimized
{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr + n, 0);
        if (sum % 2)
            return false;

        sum = sum / 2;
        vector<int> prev(sum + 1, 0);
        prev[0] = 1;

        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> temp(sum + 1, 0);
            for (int target = 1; target <= sum; target++)
            {
                int not_taken = prev[target], taken = false;
                if (arr[idx] <= target)
                    taken = prev[target - arr[idx]];
                temp[target] = not_taken or taken;
            }
            prev = temp;
        }
        return prev[sum];
    }
};
int main()
{
}