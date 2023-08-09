/*
Gfg:https://practice.geeksforgeeks.org/problem-of-the-day
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string str, string pat)
    {
        int len1 = str.length(), len2 = pat.length();
        int i = 0, j = 0, start_index = -1, min_len = INT_MAX;
        string ans = "";
        while (i < len1)
        {
            if (str[i] == pat[j])
            {
                if (!j)
                    start_index = i;

                if (j == len2 - 1 and min_len > i - start_index + 1)
                {
                    min_len = i - start_index + 1;
                    ans = str.substr(start_index, min_len);
                    i = start_index;
                }

                j = (j + 1) % len2;
            }
            i++;
        }
        return ans;
    }
};
int main()
{
}