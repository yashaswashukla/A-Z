/*
Gfg:https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1003;
    long long helper(int start, int end, bool isTrue, string s, vector<vector<vector<long long>>> &dp)
    {
        if (start > end)
            return 0;
        if (start == end)
            return isTrue ? s[start] == 'T' : s[start] == 'F';
        if (dp[start][end][isTrue] != -1)
            return dp[start][end][isTrue];
        long long ways = 0;
        for (int part = start + 1; part < end; part += 2)
        {
            long long leftTrue = helper(start, part - 1, 1, s, dp);
            long long leftFalse = helper(start, part - 1, 0, s, dp);
            long long rightTrue = helper(part + 1, end, 1, s, dp);
            long long rightFalse = helper(part + 1, end, 0, s, dp);
            if (s[part] == '&')
            {
                if (isTrue)
                    ways = (ways + (leftTrue * rightTrue) % mod) % mod;
                else
                    ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (rightFalse * leftFalse) % mod) % mod;
            }
            else if (s[part] == '|')
            {
                if (isTrue)
                    ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
                else
                    ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
            else if (s[part] == '^')
            {
                if (isTrue)
                    ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
                else
                    ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
        }
        return dp[start][end][isTrue] = ways;
    }
    int countWays(int N, string S)
    {
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, -1)));
        return helper(0, N - 1, 1, S, dp);
    }
};
class tabSolution
{
    int mod = 1003;
    int countWays(int N, string s)
    {
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, 0)));
        for (int start = N - 1; start >= 0; start--)
            for (int end = start; end < N; end++)
            {
                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {

                    if (start == end)
                    {
                        dp[start][end][isTrue] = isTrue ? s[start] == 'T' : s[start] == 'F';
                        continue;
                    }

                    long long ways = 0;
                    for (int part = start + 1; part < end; part += 2)
                    {
                        long long leftTrue = dp[start][part - 1][1];
                        long long leftFalse = dp[start][part - 1][0];
                        long long rightTrue = dp[part + 1][end][1];
                        long long rightFalse = dp[part + 1][end][0];

                        if (s[part] == '&')
                        {
                            if (isTrue)
                                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
                            else
                                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (rightFalse * leftFalse) % mod) % mod;
                        }
                        else if (s[part] == '|')
                        {
                            if (isTrue)
                                ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
                            else
                                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
                        }
                        else if (s[part] == '^')
                        {
                            if (isTrue)
                                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
                            else
                                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
                        }
                    }
                    dp[start][end][isTrue] = ways;
                }
            }
        return dp[0][N - 1][1];
    }
};
int main()
{
}