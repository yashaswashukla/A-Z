/*
GFG: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
Leetcode: https://leetcode.com/problems/climbing-stairs/
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dp(n + 1, -1);
class recSolution
{
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};
class dynamicSolution
{
    int mem(int n)
    {
        // Top-down approach, taking the solution of previously solved answer
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = mem(n - 1) + mem(n - 2);
    }

    int tab(int n)
    {
        // bottom-up approach, finding the last and building the fibonacci till n
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    int spaceOptimised(int n)
    {
        // Space can be saved as we are only using previous 2 values and it can also be stored in two variables and no need for extra space
        if (n <= 2)
            return n;

        int prev1 = 2, prev2 = 1;
        // If we are on the first step then there is only one way but if we are on 2nd step there are 2

        // Starting the loop from 3rd step as 1st and 2nd are stored
        for (int i = 3; i <= n; i++)
        {
            int curi = prev1 + prev2;
            prev2 = prev1;
            prev1 = curi;
        }

        return prev1;
    }
};
int main()
{
}