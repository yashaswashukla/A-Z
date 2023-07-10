/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        return ans;
    }
};
class spaceOptimized
{
public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            prev = curr;
        }
        return ans;
    }
};
int main()
{
}