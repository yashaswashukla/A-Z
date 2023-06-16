/*
Gfg:https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long merge(long long arr[], int low, int mid, int high)
    {
        long long count = 0;
        int l1 = mid - low + 1, l2 = high - mid;
        long long first[l1], second[l2];

        int i = low, k = 0, j = mid + 1;
        while (i <= mid)
            first[k++] = arr[i++];

        i = mid + 1, k = 0;
        while (i <= high)
            second[k++] = arr[i++];

        i = 0, k = low, j = 0;

        while (i < l1 and j < l2)
        {
            if (first[i] <= second[j])
                arr[k++] = first[i++];
            else
            {
                count += l1 - i;
                arr[k++] = second[j++];
            }
        }
        while (i < l1)
            arr[k++] = first[i++];

        while (j < l2)
            arr[k++] = second[j++];
        return count;
    }
    long long mergesort(long long arr[], int low, int high)
    {
        long long count = 0;
        if (low < high)
        {
            int mid = low + (high - low) / 2;

            count += mergesort(arr, low, mid);
            count += mergesort(arr, mid + 1, high);

            count += merge(arr, low, mid, high);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N - 1);
    }
};
int main()
{
}