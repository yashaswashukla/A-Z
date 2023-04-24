/*
GFG:https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maxOdd(string s)
    {
        for (int i = (int)s.length() - 1; i >= 0; i--)
            if ((s[i] - '0') % 2)
                return s.substr(0, i + 1);
        return "";
    }
};
int main()
{
}