/*
GFG: https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if (a.length() != b.length())
            return false;
        int hash[26] = {0};

        for (auto x : a)
            hash[x - 'a']++;

        for (auto x : b)
            hash[x - 'a']--;

        for (int i = 0; i < 26; i++)
            if (hash[i] != 0)
                return false;
        return true;
    }
};
int main()
{
}