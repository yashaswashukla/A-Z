/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        stringstream ss(S);
        S.clear();
        string ans;
        while (getline(ss, S, '.'))
            ans = S + '.' + ans;
        ans.pop_back();
        return ans;
    }
};
int main()
{
}