/*
GFG:https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void sort012(int arr[], int n)
    {
        // code here
        int low = 0, mid = 0, high = 0;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[mid], arr[low]);
                low++, mid++;
            }
            else if (arr[mid] == 2)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
            else if (arr[mid] == 1)
                mid++;
        }
    }
};
int main()
{
}