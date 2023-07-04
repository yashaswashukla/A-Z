/*
Gfg:https://practice.geeksforgeeks.org/problems/geeks-training/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<vector<int>> &point, int day, int last, vector<vector<int>> &dp)
    {
        if (dp[day][last] != -1)
            return dp[day][last];
        if (!day)
        {
            int maxpoint = -1;
            for (int i = 0; i < 3; i++)
                if (i != last)
                    maxpoint = max(maxpoint, point[day][i]);
            return dp[day][last] = maxpoint;
        }

        int maxpoint = -1;
        for (int i = 0; i < 3; i++)
            if (i != last)
                maxpoint = max(maxpoint, point[day][i] + solve(point, day - 1, i, dp));
        return dp[day][last] = maxpoint;
    }
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(points, n - 1, 3, dp);
    }
};
class tabSolution
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][2], points[0][0]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
            for (int last = 0; last < 4; last++)
                for (int task = 0; task < 3; task++)
                    if (task != last)
                        dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);

        return dp[n - 1][3];
    }
};
class spaceOptimized
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<int> dp(4, 0);

        dp[0] = max(points[0][1], points[0][2]);
        dp[1] = max(points[0][2], points[0][0]);
        dp[2] = max(points[0][1], points[0][0]);
        dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
                for (int task = 0; task < 3; task++)
                    if (task != last)
                        temp[last] = max(temp[last], points[day][task] + dp[task]);

            dp = temp;
        }
        return dp[3];
    }
};
int main()
{
}