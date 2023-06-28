/*
Gfg:https://practice.geeksforgeeks.org/problems/good-numbers4629/1
Leetcode:https://leetcode.com/problems/count-good-numbers/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool good(int n, int D)
    {
        int nn = n;
        int x = nn % 10, sum = x;
        nn /= 10;
        if (x == D)
            return false;
        while (nn)
        {
            int d = nn % 10;
            if (d == D or d <= sum)
                return false;
            sum += d;
            nn /= 10;
        }
        return true;
    }
    vector<int> goodNumbers(int L, int R, int D)
    {
        vector<int> ans;
        for (int i = L; i <= R; i++)
            if (good(i, D))
                ans.push_back(i);
        return ans;
    }
};
class leetSolution
{
public:
    int countGoodNumbers(long long n)
    {
    }
};
int main()
{
}