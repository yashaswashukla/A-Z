/*
Gfg:https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> ans;
    void helper(char str[], int k, int idx)
    {
        if (idx == k)
        {
            ans.push_back(str);
            return;
        }
        if (str[idx - 1] == '0')
        {
            str[idx] = '1';
            helper(str, k, idx + 1);
            str[idx] == '0';
            helper(str, k, idx + 1);
        }
        if (str[idx - 1] == '1')
        {
            str[idx] = '0';
            helper(str, k, idx + 1);
        }
    }
    vector<string> generateAllStrings(int k)
    {
        char str[k];
        str[0] = '0';
        helper(str, k, 1);
        str[0] = '1';
        helper(str, k, 1);
    }
};
int main()
{
}