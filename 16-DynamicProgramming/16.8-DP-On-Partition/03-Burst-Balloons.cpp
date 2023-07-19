/*
Gfg:https://practice.geeksforgeeks.org/problems/burst-balloons/1
Leetcode:https://leetcode.com/problems/burst-balloons/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int start, int end, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int maxi = 0;
        for (int partition = start; partition <= end; partition++)
        {
            int coins = arr[partition] * arr[end + 1] * arr[start - 1] + helper(start, partition - 1, arr, dp) + helper(partition + 1, end, arr, dp);
            maxi = max(maxi, coins);
        }
        return dp[start][end] = maxi;
    }
    int maxCoins(int N, vector<int> &arr)
    {
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return helper(1, N, arr, dp);
    }
};
class tabSolution
{
public:
    int maxCoins(int N, vector<int> &arr)
    {
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));

        for (int start = N; start >= 1; start--)
            for (int end = start; end <= N; end++)
            {
                int maxi = 0;
                for (int partition = start; partition <= end; partition++)
                {
                    int cost = arr[start - 1] * arr[partition] * arr[end + 1] + dp[start][partition - 1] + dp[partition + 1][end];
                    maxi = max(maxi, cost);
                }
                dp[start][end] = maxi;
            }
        return dp[1][N];
    }
};
int main()
{
}