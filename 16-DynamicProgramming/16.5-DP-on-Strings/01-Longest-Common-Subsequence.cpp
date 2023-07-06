/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (idx1 < 0 or idx2 < 0)
            return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (s1[idx1] == s2[idx2])
            return dp[idx1][idx2] = 1 + solve(idx1 - 1, idx2 - 1, s1, s2, dp);
        return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, s1, s2, dp), solve(idx1, idx2 - 1, s1, s2, dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x, vector<int>(y, -1));
        return solve(x - 1, y - 1, s1, s2, dp);
    }
};
class tabSolution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int idx1 = 1; idx1 < x + 1; idx1++)
            for (int idx2 = 1; idx2 < y + 1; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        return dp[x][y];
    }
};
class spaceOptimized
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<int> prev(y + 1, 0), curr(y + 1, 0);
        for (int idx1 = 1; idx1 <= x; idx1++)
        {
            for (int idx2 = 1; idx2 <= y; idx2++)
            {
                if (s1[idx1 - 1] == s2[idx2 - 1])
                    curr[idx2] = 1 + prev[idx2 - 1];
                else
                    curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
            }
            prev = curr;
        }
        return prev[y];
    }
};
int main()
{
}