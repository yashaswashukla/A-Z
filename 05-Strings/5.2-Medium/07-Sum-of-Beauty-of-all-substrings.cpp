/*
Gfg:https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1
Leetcode:https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int beautySum(string s)
    {
        int n = (int)s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int maxfreq = 0, minfreq = n;
                for (int i = 0; i < 26; i++)
                {
                    maxfreq = max(maxfreq, freq[i]);
                    if (freq[i])
                        minfreq = min(minfreq, freq[i]);
                }

                ans += maxfreq - minfreq;
            }
        }

        return ans;
    }
};
int main()
{
}