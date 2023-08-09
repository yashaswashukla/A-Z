/*
Gfg:
Leetcode:https://leetcode.com/problems/minimum-window-substring/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string str, string pat)
    {
        int len1 = (int)str.length(), len2 = (int)pat.length();
        if (len1 < len2)
            return "";

        int hash1[128] = {0}, hash2[128] = {0};

        for (auto x : pat)
            hash2[x]++;

        int left = 0, right = 0, start_index = -1, min_len = INT_MAX, count = 0;

        for (; right < len1; right++)
        {
            hash1[str[right]]++;
            if (hash1[str[right]] <= hash2[str[right]])
                count++;

            if (count >= len2)
            {
                while (hash1[str[left]] > hash2[str[left]] or !hash2[str[left]])
                {
                    hash1[str[left]]--;
                    left++;
                }
                int currlen = right - left + 1;
                if (currlen < min_len)
                {
                    min_len = currlen;
                    start_index = left;
                }
            }
        }

        if (start_index == -1)
            return "";
        return str.substr(start_index, min_len);
    }
};
int main()
{
}