/*
GFG:https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid < n - 1 and arr[mid] == arr[mid + 1])
            {
                if ((high - mid) % 2)
                    high = mid - 1;
                else
                    low = mid + 2;
            }
            else if (mid > 0 and arr[mid] == arr[mid - 1])
            {
                if ((mid - low) % 2)
                    low = mid + 1;
                else
                    high = mid - 2;
            }
            else
                return arr[mid];
        }
        return -1;
    }
};
int main()
{
}