/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-repeating-character-replacement/1
Leetcode:https://leetcode.com/problems/longest-repeating-character-replacement/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, count = 0, ans = 0, hash[26] = {0};

        for (; right < (int)s.length(); right++)
        {
            hash[s[right] - 'A']++;
            count = max(count, hash[s[right] - 'A']);

            while (right - left + 1 - count > k)
            {
                hash[s[left] - 'A']--;
                left--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
int main()
{
}