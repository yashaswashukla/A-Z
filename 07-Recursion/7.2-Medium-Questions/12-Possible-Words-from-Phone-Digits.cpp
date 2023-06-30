/*
Gfg:https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1
Leetcode:https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(int arr[], int idx, int n, vector<string> &ans, string temp, vector<string> &keypad)
    {
        if (idx >= n)
        {
            ans.push_back(temp);
            return;
        }

        string s = keypad[arr[idx]];

        for (int i = 0; i < (int)s.length(); i++)
            helper(arr, idx + 1, n, ans, temp + s[i], keypad);
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        helper(a, 0, N, ans, "", keypad);
        return ans;
    }
};
int main()
{
}