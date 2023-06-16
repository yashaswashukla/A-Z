/*
Gfg:
Leetcode:https://leetcode.com/problems/reverse-pairs/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int merge(vector<int> &arr, int start, int end)
    {
        int mid = start + (end - start) / 2;
        int inv = 0;
        int len1 = mid - start + 1;
        int len2 = end - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end and arr[i] > 2ll * arr[j])
                j++;

            inv += j - (mid + 1);
        }

        int mainArrayIndex = start;
        for (int i = 0; i < len1; i++)
            first[i] = arr[mainArrayIndex++];

        mainArrayIndex = mid + 1;
        for (int i = 0; i < len2; i++)
            second[i] = arr[mainArrayIndex++];

        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = start;
        while (index1 < len1 && index2 < len2)
        {
            if (first[index1] <= second[index2])
                arr[mainArrayIndex++] = first[index1++];
            else
                arr[mainArrayIndex++] = second[index2++];
        }

        while (index1 < len1)
            arr[mainArrayIndex++] = first[index1++];

        while (index2 < len2)
            arr[mainArrayIndex++] = second[index2++];
        return inv;
    }

    int mergeSort(vector<int> &arr, int start, int end)
    {
        int inv = 0;
        if (start >= end)
            return inv;

        int mid = start + (end - start) / 2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid + 1, end);

        inv += merge(arr, start, end);

        return inv;
    }

    int reversePairs(vector<int> &arr, int n)
    {
        mergeSort(arr, 0, n - 1);
    }
};
int main()
{
}