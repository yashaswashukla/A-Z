/*
GFG:https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int largest(vector<int> &arr, int n)
    {
        int ma = arr[0];
        for (int i = 1; i < n; i++)
            ma = max(arr[i], ma);
        return ma;
    }
};
int main()
{
}