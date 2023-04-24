/*
GFG:https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int find_first(int arr[], int n, int x)
    {
        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = right + (left - right) / 2;

            if (arr[mid] == x)
            {
                ans = mid;
                right = mid - 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
    int find_last(int arr[], int n, int x)
    {
        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = right + (left - right) / 2;

            if (arr[mid] == x)
            {
                ans = mid;
                left = mid + 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }

public:
    int count(int arr[], int n, int x)
    {
        int first = find_first(arr, n, x), last = find_last(arr, n, x);
        return (first == -1 and last == -1) ? 0 : last - first + 1;
    }
};
class stlSolution
{
public:
    int count(int arr[], int n, int x)
    {
        /* get the index of first occurrence of x */
        int *low = lower_bound(arr, arr + n, x);

        // If element is not present, return 0
        if (low == (arr + n) || *low != x)
            return 0;

        /* Else get the index of last occurrence of x.
           Note that we  are only looking in the
           subarray after first occurrence */
        int *high = upper_bound(low, arr + n, x);

        /* return count */
        return high - low;
    }
};
int main()
{
}