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
        int left = 0, right = 0, zero = 0, ans = 0;
        while (right < s.size())
        {
            if (s[right] != s[left])
                zero++;
            while (zero > k)
            {
                if (s[left] != s[right])
                    zero--;
                left++;
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