/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
Leetcode:https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int arr[], int n, int idx, int prev, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int not_take = f(arr, n, idx + 1, prev, dp), take = 0;

        if (prev == -1 or arr[idx] > arr[prev])
            take = f(arr, n, idx + 1, idx, dp) + 1;

        return dp[idx][prev + 1] = max(not_take, take);
    }
    int f2(int arr[], int idx, int prev, vector<vector<int>> &dp)
    {
        if (idx < 0)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int not_take = f2(arr, idx - 1, prev, dp), take = 0;

        if (prev == -1 or arr[prev] > arr[idx])
            take = f2(arr, idx - 1, idx, dp) + 1;

        return dp[idx][prev + 1] = max(take, not_take);
    }
    int longestSubsequence(int n, int arr[])
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return f(arr, n, 0, -1, dp);
        return f2(arr, n - 1, -1, dp);
    }
};
class tabSolution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int not_take = dp[i + 1][prev + 1], take = 0;

                if (prev == -1 or arr[prev] < arr[i])
                    take = dp[i + 1][i + 1];

                dp[i][prev + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
};
class spaceOptimized
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> next(n + 1, 0), cur(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int not_take = next[prev + 1], take = 0;
                if (prev == -1 or arr[prev] < arr[i])
                    take = next[i + 1] + 1;

                cur[prev + 1] = max(take, not_take);
            }
            next = cur;
        }
        return next[0];
    }
};
class spaceOptimizedTotal
{
    int longestSubseqeunce(int n, int arr[])
    {
        vector<int> dp(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
                if (arr[prev] < arr[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
int main()
{
}