/*
GFG: https://practice.geeksforgeeks.org/problems/peak-element/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class naiveSolution
{
    int peakElement(int arr[], int n)
    {
        int l = 0, h = n - 1;
        while (h >= l)
        {
            int mid = (h + l) / 2;
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
                (mid == n - 1 || arr[mid + 1] <= arr[mid]))
                return mid;

            if (mid > 0 && arr[mid - 1] > arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
    }
};

// now using the position of low and high pointers at the end of the search
// Finding the element that has it's value greater than the next value
// and Considering the rest array as sorted.
class betterSolution
{
public:
    int peakElement(int arr[], int n)
    {
        // Your code here

        int low = 0, high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};

int main()
{
}