/*
Gfg:https://practice.geeksforgeeks.org/problems/chocolates-pickup/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class memSolution
{
public:
    int solve(int row, int col1, int col2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (col1 < 0 or col1 >= m or col2 < 0 or col2 >= m)
            return -1e8;
        if (row == n - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int maxi = -1e8;
        for (int m1 = -1; m1 <= 1; m1++)
        {
            for (int m2 = -1; m2 <= 1; m2++)
            {
                if (col1 == col2)
                    maxi = max(maxi, solve(row + 1, col1 + m1, col2 + m2, n, m, grid, dp) + grid[row][col1]);
                else
                    maxi = max(maxi, solve(row + 1, col1 + m1, col2 + m2, n, m, grid, dp) + grid[row][col1] + grid[row][col2]);
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};
class tabSolution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        for (int col1 = 0; col1 < m; col1++)
            for (int col2 = 0; col2 < m; col2++)
                if (col1 == col2)
                    dp[n - 1][col1][col2] = grid[n - 1][col1];
                else
                    dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];

        for (int row = n - 2; row >= 0; row--)
            for (int col1 = 0; col1 < m; col1++)
                for (int col2 = 0; col2 < m; col2++)
                    for (int m1 = -1; m1 <= 1; m1++)
                        for (int m2 = -1; m2 <= 1; m2++)
                        {
                            int ncol1 = col1 + m1, ncol2 = col2 + m2;
                            if (ncol1 >= 0 and ncol2 >= 0 and ncol1 < m and ncol2 < m)
                            {
                                if (col1 == col2)
                                    dp[row][col1][col2] = max(dp[row][col1][col2], dp[row + 1][col1 + m1][col2 + m2] + grid[row][col1]);
                                else
                                    dp[row][col1][col2] = max(dp[row][col1][col2], dp[row + 1][col1 + m1][col2 + m2] + grid[row][col1] + grid[row][col2]);
                            }
                        }

        return dp[0][0][m - 1];
    }
};
int main()
{
}