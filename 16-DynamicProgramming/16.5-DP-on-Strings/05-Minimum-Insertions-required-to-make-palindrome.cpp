/*
Gfg:https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
Leetcode:https://leetcode.com/problems/delete-operation-for-two-strings/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Just find out the longest palindromic subsequence and then just subtract it with total size and that's the answer
    int longestPalindromicSubsequnce(string str)
    {
        int n = (int)str.length();
        string t = str;
        reverse(t.begin(), t.end());
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
    int countMin(string str)
    {
        return str.length() - longestPalindromicSubsequnce(str);
    }
};
int main()
{
}