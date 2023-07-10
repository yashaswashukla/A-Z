/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
        return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    }
    int longestPalinSubseq(string s)
    {
        int n = (int)s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};
class tabSolution
{
public:
    int longestPalinSubseq(string s)
    {
        int n = (int)s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[n][n];
    }
};
class spaceOptimized
{
public:
    int longestPalinSubseq(string s)
    {
        int n = (int)s.length();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};
int main()
{
}