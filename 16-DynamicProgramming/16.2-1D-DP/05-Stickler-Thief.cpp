/*
Gfg:https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int arr[], int n, vector<int> &dp)
    {
        if (!n)
            return 0;
        if (n == 1)
            return arr[n];

        if (dp[n] != -1)
            return dp[n];
        return dp[n] = max(arr[n] + solve(arr, n - 2, dp), solve(arr, n - 1, dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, -1);
        return solve(arr, n - 1, dp);
    }
};
int main()
{
}