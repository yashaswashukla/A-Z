/*
GFG:
Leetcode: https://leetcode.com/problems/remove-outermost-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = (int)s.length() - 1, i = n, balanced = 0;
        while (i >= 0)
        {
            if (s[i] == ')')
                balanced++;
            else
            {
                balanced--;
                if (!balanced)
                {
                    s.erase(n, 1);
                    s.erase(i, 1);
                    n = i - 1;
                }
            }
            i--;
        }
        return s;
    }
};
int main()
{
}