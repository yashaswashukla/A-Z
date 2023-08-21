/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int ans = 1, count = 1, i = 1, j = 0;
        while (i < n and j < n)
        {
            if (arr[i] <= dep[j])
                count++, i++;
            else
                count--, j++;
            ans = max(ans, count);
        }
        return ans;
    }
};
int main()
{
}