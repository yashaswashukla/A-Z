/*
Gfg:https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1
Leetcode:https://leetcode.com/problems/unique-paths/
*/
#include <bits/stdc++.h>
using namespace std;
class memSolution
{
public:
    int solve(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 or col == 0)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = solve(row - 1, col, dp) + solve(row, col - 1, dp);
    }
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return solve(a - 1, b - 1, dp);
    }
};
class tabSolution
{
public:
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a, vector<int>(b, 1));
        for (int i = 1; i < a; i++)
            for (int j = 1; j < b; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[a - 1][b - 1];
    }
};
class spaceOptimized
{
public:
    int NumberOfPath(int a, int b)
    {
        vector<int> row(b, 1);
        for (int i = 1; i < a; i++)
        {
            vector<int> temprow(b);
            temprow[0] = 1;
            for (int j = 1; j < b; j++)
                temprow[j] = row[j] + temprow[j - 1];
            row = temprow;
        }
        return row[b - 1];
    }
};
int main()
{
}