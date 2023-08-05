/*
Gfg:https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1
Leetcode:https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;
        int ans = 0;
        unordered_set<char> hash;
        while (right < (int)s.length())
        {
            while (hash.count(s[right]))
            {
                hash.erase(s[left]);
                left++;
            }
            hash.insert(s[right]);
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
int main()
{
}