/*
Gfg:
CodingNinjas: https://www.codingninjas.com/studio/problems/distinct-characters_2221410
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kDistinctChars(int k, string &str)
    {
        unordered_map<char, int> hash;
        int ans = 0, left = 0, right = 0;
        for (; right < (int)str.length(); right++)
        {
            hash[str[right]]++;
            if (hash.size() > k)
            {
                hash[str[left]]--;
                if (hash[str[left]] == 0)
                    hash.erase(str[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
int main()
{
}