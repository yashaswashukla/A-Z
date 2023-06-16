/*
Gfg:https://practice.geeksforgeeks.org/problems/implement-atoi/1
Leetcode:https://leetcode.com/problems/string-to-integer-atoi/
*/
#include <bits/stdc++.h>
using namespace std;
class gfgSolution
{
    int atoi(string s)
    {
        // Your code here
        int n = (int)s.length(), i = 0;
        double num = 0;
        while (s[i] == ' ')
            i++;

        bool pos = s[i] == '+';
        bool neg = s[i] == '-';

        if (pos or neg)
            i++;

        while (i < n)
        {
            if (s[i] >= '0' and s[i] <= '9')
                num = num * 10 + (s[i++] - '0');
            else
                return -1;
        }

        if (neg)
            num *= -1;

        num = num > INT_MAX ? INT_MAX : num;
        num = num < INT_MIN ? INT_MIN : num;

        return int(num);
    }
};
class leetSolution
{
    int myAtoi(string s)
    {
        int n = (int)s.length(), i = 0;
        double num = 0;
        while (s[i] == ' ')
            i++;

        bool pos = s[i] == '+';
        bool neg = s[i] == '-';

        if (pos or neg)
            i++;

        while (i < n and s[i] >= '0' and s[i] <= '9')
            num = num * 10 + (s[i++] - '0');

        if (neg)
            num *= -1;

        num = num > INT_MAX ? INT_MAX : num;
        num = num < INT_MIN ? INT_MIN : num;

        return int(num);
    }
};
int main()
{
}