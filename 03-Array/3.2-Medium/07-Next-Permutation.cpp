/*
GFG:https://practice.geeksforgeeks.org/problems/next-permutation5226/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // To get the just next greater permutation we have to keep the longest prefix
        // Which means we start from back

        int j = N - 1;
        while (j >= 0)
        {
            if (j != 0 and arr[j - 1] >= arr[j])
                j--;
            else
                break;
        }

        if (j <= 0)
        {
            reverse(arr.begin(), arr.end());
            // meaning the entire array is in descending order hence no greater permutation possible
            return arr;
        }

        // In the remaining part we can now, replace the (j-1)th digit with the first digit greater than the current
        // Now we swap them

        for (int i = N - 1; i >= j; i--)
        {
            if (arr[i] > arr[j - 1])
            {
                swap(arr[i], arr[j - 1]);
                break;
            }
        }

        // rearranging the part right of j including j
        // As it is already in descending order hence new rearrangement which will be smaller will be reverse of it
        reverse(arr.begin() + j, arr.end());

        return arr;
    }
};
int main()
{
}