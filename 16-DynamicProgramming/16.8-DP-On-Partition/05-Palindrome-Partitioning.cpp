/*
Gfg:https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
Leetcode:https://leetcode.com/problems/palindrome-partitioning-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool palindrome(int left, int right, string str)
    {
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++, right--;
        }
        return true;
    }
    int helper(int idx, int n, string str, vector<int> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int mini = INT_MAX;
        for (int i = idx; i < n; i++)
            if (palindrome(idx, i, str))
                mini = min(mini, 1 + helper(i + 1, n, str, dp));
        return dp[idx] = mini;
    }
    int palindromicPartition(string str)
    {
        int n = (int)str.length();
        vector<int> dp(n, -1);
        return helper(0, n, str, dp);
    }
};
class tabSolution
{
public:
    bool palindrome(int left, int right, string str)
    {
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++, right--;
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n = (int)str.length();
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            int mini = INT_MAX;
            for (int part = idx; part < n; part++)
                if (palindrome(idx, part, str))
                    mini = min(mini, 1 + dp[part + 1]);
            dp[idx] = mini;
        }
        return dp[0];
    }
};
int main()
{
}