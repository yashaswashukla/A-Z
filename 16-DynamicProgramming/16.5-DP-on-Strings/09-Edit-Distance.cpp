/*
Gfg:https://practice.geeksforgeeks.org/problems/edit-distance3702/1
Leetcode:https://leetcode.com/problems/edit-distance/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = helper(s, t, i - 1, j - 1, dp);
        int insert = helper(s, t, i, j - 1, dp) + 1;
        int del = helper(s, t, i - 1, j, dp) + 1;
        int replace = helper(s, t, i - 1, j - 1, dp) + 1;
        return min(insert, min(del, replace));
    }
    int editDistance(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(s, t, n - 1, m - 1, dp);
    }
};
class tabSolution
{
public:
    int editDistance(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
        return dp[n][m];
    }
};
class spaceOptimized
{
public:
    int editDistance(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++)
            prev[j] = j;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = min(prev[j], min(prev[j - 1], curr[j - 1])) + 1;
            }
            prev = curr;
        }
        return prev[m];
    }
};
int main()
{
}