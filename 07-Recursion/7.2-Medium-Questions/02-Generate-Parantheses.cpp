/*
Gfg:https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(string &temp, vector<string> &ans, int open, int close, int n)
    {
        if (!open and !close)
        {
            ans.push_back(temp);
            return;
        }
        if ((int)temp.length() >= n or open < 0 or close < 0)
            return;

        temp += '(';
        helper(temp, ans, open - 1, close, n);
        temp.pop_back();
        if (open < close)
        {
            temp += ')';
            helper(temp, ans, open, close - 1, n);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        string temp = "(";
        helper(temp, ans, n - 1, n, 2 * n);
        return ans;
    }
};
int main()
{
}