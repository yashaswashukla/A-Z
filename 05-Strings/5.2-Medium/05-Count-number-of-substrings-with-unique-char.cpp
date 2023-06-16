/*
Gfg:https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long atmost(string &s, int k)
    {
        if (!s.length())
            return 0;
        int hash[26] = {0};
        long long count = 0;
        int left = 0, distinct = 0;

        for (int i = 0; i < (int)s.length(); i++)
        {
            if (!hash[s[i] - 'a'])
                distinct++;
            hash[s[i] - 'a']++;

            while (distinct > k)
            {
                hash[s[left] - 'a']--;
                if (!hash[s[left] - 'a'])
                    distinct--;
                left++;
            }
            count += i - left + 1;
        }
        return count;
    }
    long long int substrCount(string s, int k)
    {
        return atmost(s, k) - atmost(s, k - 1);
    }
};
int main()
{
}