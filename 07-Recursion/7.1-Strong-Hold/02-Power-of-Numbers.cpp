/*
Gfg:https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
Leetcode:https://leetcode.com/problems/powx-n/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    long long power(int N, int R)
    {
        if (!R)
            return 1;
        if (R == 1)
            return N;
        long long ans = (power(N, R / 2) % mod);
        ans = (ans * ans) % mod;
        return R % 2 ? (N * ans) % mod : ans % mod;
    }
};
class leetSolution
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return (double)1;
        if (n == 1 or x == 1 or x == 0)
            return x;

        double ans = myPow(x, n / 2);
        ans = ans * ans;
        return n % 2 ? n < 0 ? (1 / x) * ans : x * ans : ans;
    }
};
int main()
{
}