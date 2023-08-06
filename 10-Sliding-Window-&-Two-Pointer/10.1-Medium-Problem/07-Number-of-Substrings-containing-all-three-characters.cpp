/*
Gfg:https://practice.geeksforgeeks.org/problems/count-substring/1
Leetcode:https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int hash[3] = {0};
        int left = 0, right = 0, ans = 0;

        for (; right < n; right++)
        {
            hash[s[right] - 'a']++;
            while (hash[0] and hash[1] and hash[2])
            {
                hash[s[left] - 'a']--;
                left++;
                ans += n - right;
            }
        }
        return ans;
    }
};
int main()
{
}