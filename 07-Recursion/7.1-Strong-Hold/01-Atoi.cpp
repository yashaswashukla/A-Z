/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(string str, int idx)
    {
        int n = (int)str.length();
        if (idx >= n)
            return 0;
        if (str[idx] - '0' >= 0 and str[idx] - '0' < 10)
            return helper(str, idx + 1) == -1 ? -1 : (str[idx] - '0') * pow(10, n - 1 - idx) + helper(str, idx + 1);
        return -1;
    }
    int atoi(string str)
    {
        if (str[0] == '-')
            return helper(str, 1) == -1 ? -1 : -1 * helper(str, 1);

        return helper(str, 0);
    }
};
class iterSolution
{
public:
    int atoi(string str)
    {
        int n = (int)str.length();
        int i = 0;
        while (str[i] == ' ')
            i++;
        bool pos = str[i] == '+';
        bool neg = str[i] == '-';

        if (pos or neg)
            i++;
        double ans = 0;
        while (i < n)
        {
            if (str[i] >= '0' and str[i] <= '9')
                ans = ans * 10 + str[i++] - '0';
            else
                break;
        }
        if (neg)
            ans *= -1;
        ans = ans > INT_MAX ? INT_MAX : ans;
        ans = ans < INT_MIN ? INT_MIN : ans;
        return ans;
    }
};
int main()
{
}