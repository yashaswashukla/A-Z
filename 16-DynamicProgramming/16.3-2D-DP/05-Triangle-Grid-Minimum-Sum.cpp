/*
Gfg:
Leetcode:https://leetcode.com/problems/triangle/
*/
#include <bits/stdc++.h>
using namespace std;
class memSolution
{
public:
    int solve(int row, int col, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (row >= n or col >= n)
            return INT_MAX;
        if (dp[row][col] != -1)
            return dp[row][col];
        if (row == n - 1)
            return triangle[row][col];

        int mini = min(solve(row + 1, col, n, triangle, dp), solve(row + 1, col + 1, n, triangle, dp));
        return dp[row][col] = mini + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};
class tabSolution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];
        for (int row = n - 2; row >= 0; row--)
            for (int col = row; col >= 0; col--)
                dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) + triangle[row][col];
        return dp[0][0];
    }
};
class spaceOptimized
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = triangle[n - 1][i];

        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> temp(n, 0);
            for (int col = row; col >= 0; col--)
                temp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
            dp = temp;
        }
        return dp[0];
    }
};
int main()
{
}