/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-string-chain/1
Leetcode:https://leetcode.com/problems/longest-string-chain/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int first = 0, second = 0;
        while (first < a.size())
        {
            if (second < b.size() and a[first] == b[second])
                first++, second++;
            else
                first++;
        }
        return first == a.size() and second == b.size();
    }
    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }
    int f(vector<string> &words, int idx, int prev, int n, vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int not_take = f(words, idx + 1, prev, n, dp), take = 0;
        if (prev == -1 or check(words[idx], words[prev]))
            take = f(words, idx + 1, idx, n, dp) + 1;
        return dp[idx][prev + 1] = max(take, not_take);
    }
    int longestChain(int n, vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(words, 0, -1, n, dp);
    }
};
class tabSolution
{
public:
    bool check(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size())
        {
            if (j < b.size() and a[i] == b[j])
                i++, j++;
            else
                i++;
        }
        return i == a.size() and j == b.size();
    }
    static bool comp(string &a, string &b)
    {
        return a.length() < b.length();
    }
    int longestChain(int n, vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = i - 1; prev >= -1; prev--)
            {
                int not_take = dp[i + 1][prev + 1], take = 0;
                if (check(words[i], words[prev + 1]))
                    take = dp[i + 1][i + 1] + 1;
                dp[i][prev + 1] = max(not_take, take);
            }
        }
        return dp[0][0];
    }
};
class spaceOptimized
{
public:
    bool check(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size())
        {
            if (j < b.size() and a[i] == b[j])
                i++, j++;
            else
                i++;
        }
        return i == a.size() and j == b.size();
    }
    static bool comp(string &a, string &b)
    {
        return a.length() < b.length();
    }
    int longestChain(int n, vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
                if (check(words[i], words[prev]) and dp[i] < dp[prev] + 1)
                    dp[i] = dp[prev] + 1;
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main()
{
}