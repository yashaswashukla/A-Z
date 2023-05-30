/*
GFG:https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void pushZerosToEnd(int arr[], int n)
    {
        // code here
        int idx = 0;
        for (int i = 0; i < n; i++)
            if (arr[i])
                arr[idx++] = arr[i];

        while (idx < n)
            arr[idx++] = 0;
    }
};
int main()
{
}