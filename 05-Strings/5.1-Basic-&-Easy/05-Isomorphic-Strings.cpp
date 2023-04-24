/*
GFG: https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        char hash[256];
        if (n1 != n2)
            return false;

        for (int i = 0; i < n1; i++)
            hash[str1[i]] = str2[i];

        for (int i = 0; i < n1; i++)
            if (str2[i] != hash[str1[i]])
                return false;

        for (int i = 0; i < n1; i++)
            hash[str2[i]] = str1[i];
        for (int i = 0; i < n1; i++)
            if (str1[i] != hash[str2[i]])
                return false;

        return true;
    }
};
int main()
{
}