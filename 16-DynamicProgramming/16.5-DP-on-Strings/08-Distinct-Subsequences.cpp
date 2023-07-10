/*
Gfg:
Leetcode:https://leetcode.com/problems/distinct-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int helper(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp)
    {
        if (idx2 < 0)
            return 1;
        if (idx1 < 0)
            return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (s[idx1] == t[idx2])
            return dp[idx1][idx2] = (helper(s, t, idx1 - 1, idx2 - 1, dp) + helper(s, t, idx1 - 1, idx2, dp)) % mod;

        return dp[idx1][idx2] = helper(s, t, idx1 - 1, idx2, dp);
    }
    int numDistinct(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(s, t, n - 1, m - 1, dp);
    }
};
class tabSolution
{
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int idx1 = 0; idx1 <= n; idx1++)
            dp[idx1][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                else
                    dp[i][j] = dp[i - 1][j];
            }
        return dp[n][m];
    }
};
class spaceOptimized
{
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t)
    {
        int n = (int)s.length(), m = (int)t.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            curr[0] = 1;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = (prev[j - 1] + prev[j]) % mod;
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main()
{
}