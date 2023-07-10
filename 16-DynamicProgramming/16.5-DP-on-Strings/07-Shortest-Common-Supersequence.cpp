/*
Gfg:https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
public:
    // This question is again solved with the help of LCS, Let's see how:
    // Given are two strings and we have to find out the length of the smallest
    // common super sequence which will be nothing but inclusion of of both the strings
    // but, when we include both the strings we will also include the LCS twice and hence
    // we will have to remove that portion from the resultant string
    // Hence, length will be s1.length() + s2.length() - lcs(s1, s2)
    int lcs(string &x, string &y, int m, int n)
    {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return n + m - lcs(X, Y, m, n);
    }
};
class leetSolution
{
public:
    // To print one of the super sequences, we take help of the DP table that we create
    // while finding out the LCS for the two strings.
    // Now, we will use that table as while moving up or down, we include the character we leave.
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = (int)str1.length(), m = (int)str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        string ans = "";
        int i = n, j = m;
        while (i > 0 and j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans = str1[i - 1] + ans;
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                ans = str1[--i] + ans;
            else
                ans = str2[--j] + ans;
        }
        while (i > 0)
            ans = str1[--i] + ans;
        while (j > 0)
            ans = str2[--j] + ans;
        return ans;
    }
};
int main()
{
}