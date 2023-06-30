/*
Gfg:https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
Leetcode:https://leetcode.com/problems/palindrome-partitioning/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool palindrome(string &temp)
    {
        int i = 0, j = (int)temp.length() - 1;
        while (i < j)
            if (temp[i++] != temp[j--])
                return false;
        return true;
    }
    void helper(string &s, int idx)
    {
        if (idx == (int)s.length())
        {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < (int)s.length(); i++)
        {
            string temp = s.substr(idx, i - idx + 1);
            if (palindrome(temp))
            {
                path.push_back(temp);
                helper(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        helper(s, 0);
        return ans;
    }
};
int main()
{
}