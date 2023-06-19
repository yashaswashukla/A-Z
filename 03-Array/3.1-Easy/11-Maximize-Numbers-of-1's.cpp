/*
GFG:https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int findZeroes(int arr[], int n, int m)
    {
        int i = 0, j = 0, ans = 0, flips = 0;
        while (j < n)
        {
            if (!arr[j])
                flips++;
            while (flips > m)
                if (!arr[i++])
                    flips--;

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
int main()
{
}