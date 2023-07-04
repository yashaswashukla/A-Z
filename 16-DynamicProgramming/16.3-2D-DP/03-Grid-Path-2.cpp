/*
Gfg:https://practice.geeksforgeeks.org/problems/grid-path-2/1
Leetcode:https://leetcode.com/problems/unique-paths-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class memSolution
{
public:
    int mod = 1e9 + 7;
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (grid[row][col])
            return dp[row][col] = 0;
        if (!row and !col)
            return 1;
        if (col and !row)
            return dp[row][col] = solve(row, col - 1, grid, dp) % mod;
        if (!col and row)
            return dp[row][col] = solve(row - 1, col, grid, dp) % mod;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = (solve(row - 1, col, grid, dp) + solve(row, col - 1, grid, dp)) % mod;
    }
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, grid, dp);
    }
};
class tabSolution
{
public:
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if (!grid[0][0])
            dp[0][0] = 1;
        for (int col = 1; col < m; col++)
            if (dp[0][col - 1] and !grid[0][col])
                dp[0][col] = 1;

        for (int row = 1; row < n; row++)
            if (dp[row - 1][0] and !grid[row][0])
                dp[row][0] = 1;

        for (int row = 1; row < n; row++)
            for (int col = 1; col < m; col++)
                if (!grid[row][col])
                    dp[row][col] = (dp[row - 1][col] + dp[row][col - 1]) % mod;

        return dp[n - 1][m - 1];
    }
};
class spaceOptimized
{
public:
    int mod = 1e9 + 7;
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        if (grid[0][0])
            return 0;
        vector<int> row(m, 0);
        row[0] = 1;
        for (int col = 1; col < m; col++)
            if (row[col - 1] and !grid[0][col])
                row[col] = 1;

        for (int i = 1; i < n; i++)
        {
            vector<int> temprow(m, 0);
            if (!grid[i][0] and row[0])
                temprow[0] = 1;
            for (int col = 1; col < m; col++)
                if (!grid[i][col])
                    temprow[col] = (temprow[col - 1] + row[col]) % mod;
            row = temprow;
        }
        return row[m - 1];
    }
};
int main()
{
}