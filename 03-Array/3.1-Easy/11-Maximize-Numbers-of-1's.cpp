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
        // code here
        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < n)
        {

            if (arr[j] == 0)
                m--;

            if (m >= 0)
                ans = max(ans, j - i + 1);

            else if (m < 0)
            {
                while (m < 0)
                {
                    if (arr[i] == 0)
                        m++;
                    i++;
                }
            }

            if (m >= 0)
                ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};
int main()
{
}