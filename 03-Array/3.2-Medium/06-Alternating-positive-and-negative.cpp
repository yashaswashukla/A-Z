/*
GFG:https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void rearrange(int arr[], int n)
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }

        int pi = 0, ni = 0, i = 0;

        while (pi < pos.size() && ni < neg.size())
        {
            if (i % 2 == 0)
                arr[i++] = pos[pi++];
            else
                arr[i++] = neg[ni++];
        }

        while (ni < neg.size())
            arr[i++] = neg[ni++];

        while (pi < pos.size())
            arr[i++] = pos[pi++];
    }
};
int main()
{
}