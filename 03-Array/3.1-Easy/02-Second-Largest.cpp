/*
GFG:https://practice.geeksforgeeks.org/problems/second-largest3735/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int print2largest(int arr[], int n)
    {
        int ma = arr[0], ans = -1;

        for (int i = 1; i < n; i++)
            ma = max(arr[i], ma);
        for (int i = 1; i < n; i++)
            if (arr[i] < ma)
                ans = max(arr[i], ans);
        return ans;
    }
};
int main()
{
}