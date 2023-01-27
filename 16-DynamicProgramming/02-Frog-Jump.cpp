/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dp(n + 1, -1);
class recSolution
{
    int frogJump(int n, vector<int> &heights)
    {
        // if n is the last step of the staircase
        if (n == 0)
            return 0;

        int left = frogJump(n - 1, heights) + abs(heights[n] - heights[n - 1]);
        int right = INT_MAX;

        if (n > 1)
            right = frogJump(n - 2, heights) + abs(heights[n] - heights[n - 2]);

        return min(left, right);
    }
};

class dynamicSolution
{
public:
    int mem(int n, vector<int> &heights)
    {
        if (n == 0)
            return 0;
        int left = INT_MAX, right = INT_MAX;
        if (dp[n] != -1)
            return dp[n];

        left = mem(n - 1, heights) + abs(heights[n] - heights[n - 1]);

        if (n > 1)
            right = mem(n - 2, heights) + abs(heights[n] - heights[n - 2]);

        return dp[n] = min(left, right);
    }
    int tab(int n, vector<int> &heights)
    {
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int right = INT_MAX;
            if (i > 1)
                right = dp[i - 2] + abs(heights[i] - heights[i - 2]);

            dp[i] = min(left, right);
        }

        return dp[n];
    }

    int spaceOptimise(int n, vector<int> &heights)
    {
        int prev1 = abs(heights[0] - heights[1]), prev2 = 0;

        for (int i = 2; i < n; i++)
        {
            int left = prev1 + abs(heights[i] - heights[i - 1]);
            int right = prev2 + abs(heights[i] - heights[i - 2]);
            prev2 = prev1;
            prev1 = min(left, right);
        }

        return prev1;
    }
};
int main()
{
}