/*
Gfg:https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?company[]=Synopsys&company[]=Synopsys&page=1&query=company[]Synopsyspage1company[]Synopsys
Leetcode:https://leetcode.com/problems/merge-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = n - 1, j = 0;
        while (i >= 0 and j < m)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i--], arr2[j++]);
            else
                i--, j++;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
int main()
{
}