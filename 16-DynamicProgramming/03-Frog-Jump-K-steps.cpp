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
    int frogJump(int n, int k, vector<int> &heights)
    {
        // if n is the last step of the staircase
        if (n == 0)
            return n;

        int ans = INT_MAX;

        // now the jumps can be at max k so we would have to run a loop to go through all the cases
        for (int i = 1; i <= k; i++)
        {
            if (n - i >= 0)
            {
                int jump = frogJump(n - i, k, heights) + abs(heights[n] - heights[n - i]);
                ans = min(jump, ans);
            }
        }

        return ans;
    }
};

class dynamicSolution
{
public:
    int mem(int n, int k, vector<int> &heights)
    {
        if (n == 0)
            return 0;
        int left = INT_MAX, right = INT_MAX;
        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            if (n - i >= 0)
            {
                int jump = mem(n - i, k, heights) + abs(heights[n] - heights[n - i]);
                ans = min(jump, ans);
            }
        }

        return dp[n] = ans;
    }
    int tab(int n, int k, vector<int> &heights)
    {
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int ans = INT_MAX;

            for (int j = 1; j <= k and j < i; j++)
            {
                int jump = mem(n - j, k, heights) + abs(heights[i] - heights[i - j]);
                ans = min(jump, ans);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};
int main()
{
}