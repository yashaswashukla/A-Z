/*
Gfg:https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1
Leetcode:https://leetcode.com/problems/target-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class basicSolution
{
public:
    int solve(vector<int> &arr, int idx, int target, unordered_map<string, int> &dp)
    {
        if (!idx)
        {
            int count = 0;
            if (!(target - arr[idx]))
                count++;
            if (!(target + arr[idx]))
                count++;
            return count;
        }
        string s = to_string(idx) + " " + to_string(target);

        if (dp.find(s) != dp.end())
            return dp[s];
        int plus = solve(arr, idx - 1, target - arr[idx], dp), minus = solve(arr, idx - 1, target + arr[idx], dp);
        return dp[s] = plus + minus;
    }
    int findTargetSumWays(vector<int> &A, int target)
    {
        int n = A.size();
        unordered_map<string, int> dp;
        return solve(A, n - 1, target, dp);
    }
};
class betterSolution
{
public:
    int solve(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
    {
        if (!idx)
        {
            if (!sum and !arr[idx])
                return 2;
            if (!sum)
                return 1;
            return sum == arr[idx];
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int not_taken = solve(arr, idx - 1, sum, dp), taken = 0;
        if (arr[idx] <= sum)
            taken = solve(arr, idx - 1, sum - arr[idx], dp);
        return dp[idx][sum] = (not_taken + taken);
    }
    int findTargetSumWays(vector<int> &A, int target)
    {
        int sum = accumulate(A.begin(), A.end(), 0);
        sum = sum - target;
        if (sum < 0)
            return 0;
        if (sum % 2)
            return 0;
        sum = sum / 2;
        vector<vector<int>> dp(A.size(), vector<int>(sum + 1, -1));
        return solve(A, A.size() - 1, sum, dp);
    }
};
class tabSolution
{
public:
    int findTargetSumWays(vector<int> &A, int target)
    {
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        sum = sum - target;
        if (sum < 0)
            return 0;
        if (sum % 2)
            return 0;
        sum = sum / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (!A[0])
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (A[0])
            dp[0][A[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int curr = 0; curr <= sum; curr++)
            {
                int not_taken = dp[idx - 1][curr], taken = 0;
                if (A[idx] <= curr)
                    taken = dp[idx - 1][curr - A[idx]];
                dp[idx][curr] = not_taken + taken;
            }
        }
        return dp[n - 1][sum];
    }
};
class spaceOptimized
{
    int findTargetSumWays(vector<int> &arr, int target)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        sum = sum - target;
        if (sum < 0 or sum % 2)
            return 0;
        sum = sum / 2;

        vector<int> dp(sum + 1, 0);

        if (!arr[0])
            dp[0] = 2;
        else
            dp[0] = 1;

        if (arr[0] and arr[0] <= sum)
            dp[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            for (int curr = sum; curr >= 0; curr--)
            {
                int not_taken = dp[curr], taken = 0;
                if (arr[idx] <= curr)
                    taken = dp[curr - arr[idx]];
                dp[curr] = not_taken + taken;
            }
        }
        return dp[sum];
    }
};
int main()
{
}