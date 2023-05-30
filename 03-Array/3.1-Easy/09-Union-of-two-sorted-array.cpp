/*
GFG:https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0;
        int j = 0;

        vector<int> ans;
        while (i < n and j < m)
        {
            if (arr1[i] <= arr2[j]) // Case 1 and 2
            {
                if (ans.size() == 0 || ans.back() != arr1[i])
                    ans.push_back(arr1[i]);
                i++;
            }
            else // case 3
            {
                if (ans.size() == 0 || ans.back() != arr2[j])
                    ans.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n)
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        while (j < m)
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }

        return ans;
    }
};
int main()
{
}