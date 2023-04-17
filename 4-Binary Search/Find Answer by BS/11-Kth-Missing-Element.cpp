/*
GFG: https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int KthMissingElement(int a[], int n, int k)
    {
        int num = a[0], count = 0, i = 0;
        while (i < n)
        {
            if (num == a[i])
            {
                num++;
                i++;
            }
            else
            {
                count++;
                num++;
            }

            if (count == k)
                return num - 1;
        }
        return -1;
    }
};
class binarySearch
{
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] - 1 - mid < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};
int main()
{
}