/*
GFG:https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(int arr[], int n)
    {
        int low = 0, high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[high])
                high = mid;
            else
                low = mid + 1;
        }
        return arr[low];
    }
};
int main()
{
}