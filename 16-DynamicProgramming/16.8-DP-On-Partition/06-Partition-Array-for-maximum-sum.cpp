/*
Gfg:https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1?page=1&sortBy=accuracy
Leetcode:https://leetcode.com/problems/partition-array-for-maximum-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int idx, int n, int k, vector<int> &arr, vector<int> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int maxSum = -1, maxele = -1, len = 0;
        for (int part = idx; part < idx + k and part < n; part++)
        {
            len++;
            maxele = max(maxele, arr[part]);
            int sum = len * maxele + helper(part + 1, n, k, arr, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[idx] = maxSum;
    }
    int solve(int n, int k, vector<int> &arr)
    {
        vector<int> dp(n, -1);
        return helper(0, n, k, arr, dp);
    }
};
class tabSolution
{
public:
    int solve(int n, int k, vector<int> &arr)
    {
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            int maxSum = -1, maxele = -1;
            for (int part = idx; part < min(idx + k, n); part++)
            {
                maxele = max(maxele, arr[part]);
                maxSum = max(maxSum, maxele * (part - idx + 1) + dp[part + 1]);
            }
            dp[idx] = maxSum;
        }
        return dp[0];
    }
};
int main()
{
}