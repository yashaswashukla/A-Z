/*
Gfg:https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int start, int end, int arr[], vector<vector<int>> &dp)
    {
        if (start == end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int mini = INT_MAX;
        for (int k = start; k < end; k++)
        {
            int steps = arr[start - 1] * arr[k] * arr[end];
            int left = helper(start, k, arr, dp);
            int right = helper(k + 1, end, arr, dp);
            mini = min(mini, steps + left + right);
        }
        return dp[start][end] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return helper(1, N - 1, arr, dp);
    }
};
class tabSolution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int start = N - 1; start >= 1; start--)
        {
            for (int end = start + 1; end < N; end++)
            {
                int mini = INT_MAX;
                for (int part = start; part < end; part++)
                {
                    int steps = arr[start - 1] * arr[part] * arr[end];
                    int left = dp[start][part];
                    int right = dp[part + 1][end];
                    mini = min(mini, steps + left + right);
                }
                dp[start][end] = mini;
            }
        }
        return dp[1][N - 1];
    }
};
int main()
{
}