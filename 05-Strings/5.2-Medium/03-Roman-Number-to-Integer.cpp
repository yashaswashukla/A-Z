/*
Gfg:https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Leetcode:https://leetcode.com/problems/roman-to-integer/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToDecimal(string &str)
    {
        int n = (int)str.length();
        unordered_map<char, int> hash;
        hash['I'] = 1, hash['V'] = 5, hash['X'] = 10, hash['L'] = 50, hash['C'] = 100, hash['D'] = 500, hash['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1 and hash[str[i]] < hash[str[i + 1]])
                ans -= hash[str[i]];
            else
                ans += hash[str[i]];
        }
        return ans;
    }
};
int main()
{
}