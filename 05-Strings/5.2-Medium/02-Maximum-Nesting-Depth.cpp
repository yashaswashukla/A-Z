/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1
Leetcode:https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0, depth = 0;

        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] == '(')
                depth++;
            else if (s[i] == ')')
            {
                ans = max(ans, depth);
                depth--;
            }
        }
        return ans;
    }
};
int main()
{
}