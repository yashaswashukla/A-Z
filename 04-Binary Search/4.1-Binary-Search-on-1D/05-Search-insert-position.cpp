/*
GFG: https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsertK(vector<int> arr, int N, int k)
    {
        // code here
        if (k < arr[0])
            return 0;
        if (k > arr[N - 1])
            return N;
        int ans = -1;
        int left = 0, right = N - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > k or arr[mid] == k)
            {
                ans = mid;
                right = mid - 1;
            }
            else if (arr[mid] < k)
                left = mid + 1;
        }
        return ans;
    }
};
class betterSolution
{
public:
    int searchInsertK(vector<int> arr, int N, int k)
    {
        // code here
        int low = 0, high = N;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= k)
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