/*
Gfg:https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
Leetcode:https://leetcode.com/problems/wildcard-matching/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool allstars(string pat, int i)
    {
        for (int j = 0; j <= i; j++)
            if (pat[j] != '*')
                return false;
        return true;
    }
    bool helper(string pat, string str, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j < 0;
        if (j < 0)
            return allstars(pat, i);
        if (dp[i][j] != -1)
            return dp[i][j];
        if (pat[i] == '?' or pat[i] == str[j])
            return dp[i][j] = helper(pat, str, i - 1, j - 1, dp);
        if (pat[i] == '*')
            return dp[i][j] = helper(pat, str, i - 1, j, dp) or helper(pat, str, i, j - 1, dp);
        return dp[i][j] = false;
    }
    int wildCard(string pattern, string str)
    {
        int n = (int)pattern.size(), m = (int)str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(pattern, str, n - 1, m - 1, dp);
    }
};
class tabSolution
{
public:
    bool allstars(string pat, int i)
    {
        for (int j = 0; j <= i; j++)
            if (pat[j] != '*')
                return false;
        return true;
    }
    int wildCard(string pat, string str)
    {
        int n = (int)pat.length(), m = str.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = allstars(pat, i);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pat[i - 1] == '?' or pat[i - 1] == str[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pat[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
};
int main()
{
}