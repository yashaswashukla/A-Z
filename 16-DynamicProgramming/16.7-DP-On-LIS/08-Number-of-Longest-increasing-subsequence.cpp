/*
Gfg:https://practice.geeksforgeeks.org/problems/number-of-longest-increasing-subsequence/1
Leetcode:https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int NumberofLIS(int n, vector<int> &arr)
    {
        // As we already know, when we find out the length of longest increasing subsequence
        // Using tabulation gives us a resultant array which consists of the elements which
        // represent the longest increasing subsequence till that index, hence we can just find
        // out the longest increasing subsequence and then count from the dp array, to get the
        // answer;

        vector<int> dp(n, 1), count(n, 1);
        int lis = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if (dp[i] == dp[j] + 1)
                        count[i] += count[j];
                }
            }
            lis = max(lis, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == lis)
                ans += count[i];
        return ans;
    }
};
int main()
{
}