/*
Gfg:https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
Leetcode:https://leetcode.com/problems/minimum-falling-path-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int row, int col, int n, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (col < 0 or col >= n)
            return INT_MIN;
        if (!row)
            return arr[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];

        int up = solve(row - 1, col, n, arr, dp);
        int left = solve(row - 1, col - 1, n, arr, dp);
        int right = solve(row - 1, col + 1, n, arr, dp);
        return dp[row][col] = max(up, max(left, right)) + arr[row][col];
    }
    int maximumPath(int N, vector<vector<int>> arr)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int maxi = INT_MIN;
        for (int col = 0; col < N; col++)
            maxi = max(maxi, solve(N - 1, col, N, arr, dp));
        return maxi;
    }
};
class tabSolution
{
public:
    int maximumPath(int N, vector<vector<int>> arr)
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
            dp[0][i] = arr[0][i];
        for (int row = 1; row < N; row++)
        {
            dp[row][0] = max(dp[row - 1][0], dp[row - 1][1]) + arr[row][0];
            for (int col = 1; col < N - 1; col++)
                dp[row][col] = arr[row][col] + max(dp[row - 1][col], max(dp[row - 1][col + 1], dp[row - 1][col - 1]));
            dp[row][N - 1] = max(dp[row - 1][N - 1], dp[row - 1][N - 2]) + arr[row][N - 1];
        }
        int maxi = INT_MIN;
        for (int col = 0; col < N; col++)
            maxi = max(maxi, dp[N - 1][col]);
        return maxi;
    }
};
class spaceOptimized
{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    {
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
            prev[i] = arr[0][i];

        for (int row = 1; row < n; row++)
        {
            vector<int> curr(n, 0);
            curr[0] = max(prev[0], prev[1]) + arr[row][0];
            for (int col = 1; col < n - 1; col++)
                curr[col] = max(prev[col], max(prev[col - 1], prev[col + 1])) + arr[row][col];
            curr[n - 1] = max(prev[n - 1], prev[n - 2]) + arr[row][n - 1];
            prev = curr;
        }
        int maxi = INT_MIN;
        for (int col = 0; col < n; col++)
            maxi = max(maxi, prev[col]);
        return maxi;
    }
};
int main()
{
}