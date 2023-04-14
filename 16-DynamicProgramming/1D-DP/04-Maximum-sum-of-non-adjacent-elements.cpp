/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class recSolution
{
public:
    // calculate the maximum sum with out adjacent
    int dfs(int i, int *arr, int n)
    {
        if (i >= n)
            return 0;
        if (i == n - 1)
            return arr[n - 1];

        int taken = arr[i] + dfs(i + 2, arr, n);

        int not_taken = dfs(i + 1, arr, n);

        return max(taken, not_taken);
    }
    int findMaxSum(int *arr, int n)
    {
        // code here
        return dfs(0, arr, n);
    }
};
class memSolution
{
public:
    // calculate the maximum sum with out adjacent
    int dfs(int i, int *arr, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (i == n - 1)
            return arr[n - 1];

        if (dp[i] != -1)
            return dp[i];

        int taken = arr[i] + dfs(i + 2, arr, n, dp);

        int not_taken = dfs(i + 1, arr, n, dp);

        dp[i] = max(taken, not_taken);
        return dp[i];
    }
    int findMaxSum(int *arr, int n)
    {
        // code here
        vector<int> dp(n, -1);
        return dfs(0, arr, n, dp);
    }
};
class memSolution2
{
public:
    // calculate the maximum sum with out adjacent
    int dfs(int *arr, int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return arr[0];

        if (dp[n] != -1)
            return dp[n];

        int taken = arr[n] + dfs(arr, n - 2, dp);

        int not_taken = dfs(arr, n - 1, dp);

        dp[n] = max(taken, not_taken);
        return dp[n];
    }
    int findMaxSum(int *arr, int n)
    {
        // code here
        vector<int> dp(n, -1);
        return dfs(arr, n - 1, dp);
    }
};

class tabSolution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        vector<int> dp(n, -1);
        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            int taken = arr[i];
            if (i >= 2)
                taken += dp[i - 2];
            int not_taken = dp[i - 1];

            dp[i] = max(taken, not_taken);
        }
        return dp[n - 1];
    }
};
int main()
{
}