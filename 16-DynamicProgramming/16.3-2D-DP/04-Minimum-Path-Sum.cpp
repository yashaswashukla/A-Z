/*
Gfg:
Leetcode:https://leetcode.com/problems/minimum-path-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row < 0 or col < 0)
            return INT_MAX;
        if (!row and !col)
            return grid[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = min(solve(row - 1, col, grid, dp), solve(row, col - 1, grid, dp)) + grid[row][col];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, grid, dp);
    }
};
class tabSolution
{

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = grid[0][0];
        for (int row = 1; row < n; row++)
            dp[row][0] = grid[row][0] + dp[row - 1][0];
        for (int col = 1; col < m; col++)
            dp[0][col] = grid[0][col] + dp[0][col - 1];

        for (int row = 1; row < n; row++)
            for (int col = 1; col < m; col++)
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];

        return dp[n - 1][m - 1];
    }
};
class spaceOptimized
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> prevrow(m, 0);
        prevrow[0] = grid[0][0];
        for (int col = 1; col < m; col++)
            prevrow[col] = grid[0][col] + prevrow[col - 1];

        for (int row = 1; row < n; row++)
        {
            vector<int> temp(m, 0);
            temp[0] = grid[row][0] + prevrow[0];
            for (int col = 1; col < m; col++)
                temp[col] = min(temp[col - 1], prevrow[col]) + grid[row][col];
            prevrow = temp;
        }
        return prevrow[m - 1];
    }
};
int main()
{
}