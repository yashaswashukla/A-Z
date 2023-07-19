/*
Gfg:
Leetcode:https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];

        int mini = INT_MAX;
        for (int partition = start; partition <= end; partition++)
        {
            int cost = cuts[end + 1] - cuts[start - 1];
            int left = helper(start, partition - 1, cuts, dp);
            int right = helper(partition + 1, end, cuts, dp);
            mini = min(mini, cost + left + right);
        }
        return dp[start][end] = mini;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return helper(1, c, cuts, dp);
    }
};
class tabSolution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for (int start = c; start >= 1; start--)
            for (int end = start; end <= c; end++)
            {
                int mini = INT_MAX;
                for (int partition = start; partition <= end; partition++)
                {
                    int cost = cuts[end + 1] - cuts[start - 1];
                    int left = dp[start][partition - 1];
                    int right = dp[partition + 1][end];
                    mini = min(mini, cost + left + right);
                }
                dp[start][end] = mini;
            }
        return dp[1][c];
    }
};
int main()
{
}