/*
GFG: https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarysearch(int arr[], int n, int k)
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = right + (left - right) / 2;

            if (arr[mid] == k)
                return mid;
            else if (arr[mid] > k)
                right = mid - 1;
            else if (arr[mid] < k)
                left = mid + 1;
        }
        return -1;
    }
};
class anotherSolution
{
public:
    int binarysearch(int arr[], int n, int k)
    {
        int low = 0, high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= k)
                high = mid;
            else
                low = mid + 1;
        }
        return (arr[high] == k) ? high : -1;
    }
};
int main()
{
}