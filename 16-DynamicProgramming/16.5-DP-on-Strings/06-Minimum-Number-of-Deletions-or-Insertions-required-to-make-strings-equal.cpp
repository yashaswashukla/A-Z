/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
Leetcode:https://leetcode.com/problems/delete-operation-for-two-strings/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Main Logic is again to find the longest common subsequence and then subtract it from the length of
    // str1 and str2 and add them. i.e : str1.length() - lcs + str2.length() - lcs
    int lcs(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int minOperations(string str1, string str2)
    {
        return str1.length() + str2.length() - 2 * lcs(str1, str2);
    }
};
int main()
{
}