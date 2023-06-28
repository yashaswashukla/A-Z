/*
Gfg:https://practice.geeksforgeeks.org/problems/power-set4302/1
Leetcode:https://leetcode.com/problems/subsets/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(string &s, int idx, string &temp, vector<string> &ans)
    {
        ans.push_back(temp);
        for (int i = idx; i < (int)s.length(); i++)
        {
            temp += s[i];
            helper(s, i + 1, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        string temp = "";
        helper(s, 0, temp, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}