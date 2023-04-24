/*
GFG: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find minimum number of pages.
    int check(int mid, int arr[], int n, int m)
    {
        int count = 1, sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                count++;
                sum = arr[i];
            }
        }

        return count <= m;
    }
    int findPages(int A[], int N, int M)
    {
        if (N < M)
            return -1;
        int low = 0, high = 0;

        for (int i = 0; i < N; i++)
            low = max(low, A[i]), high += A[i];

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (check(mid, A, N, M))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
int main()
{
}