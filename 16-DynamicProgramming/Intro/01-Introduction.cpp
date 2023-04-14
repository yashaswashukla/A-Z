/*
GFG: https://practice.geeksforgeeks.org/problems/introduction-to-dp/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

long long dp[1001];
class Solution
{
public:
    long long int topDown(int n)
    {
        long long ans = 0;
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];
        ans = topDown(n - 1) + topDown(n - 2);
        dp[n] = ans;
        return ans;
    }
    long long int bottomUp(int n)
    {
        if (n <= 1)
            return n;

        long long int first = 0, second = 1, ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans += first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};
int main()
{
}