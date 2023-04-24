/*
GFG:https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch(int arr[], int low,
                     int high, int key)
    {
        if (high < low)
            return -1;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (key == arr[mid])
            return mid;

        if (key > arr[mid])
            return binarySearch(arr, (mid + 1), high, key);

        // else
        return binarySearch(arr, low, (mid - 1), key);
    }

    /* Function to get pivot. For array 3, 4, 5, 6, 1, 2
       it returns 3 (index of 6) */
    int findPivot(int arr[], int low, int high)
    {
        // base cases
        if (high < low)
            return -1;
        if (high == low)
            return low;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (mid < high && arr[mid] > arr[mid + 1])
            return mid;

        if (mid > low && arr[mid] < arr[mid - 1])
            return (mid - 1);

        if (arr[low] >= arr[mid])
            return findPivot(arr, low, mid - 1);

        return findPivot(arr, mid + 1, high);
    }

    /* Searches an element key in a pivoted
       sorted array arr[] of size n */

    int search(int arr[], int low, int high, int key)
    {
        int n = high + 1;
        int pivot = findPivot(arr, 0, n - 1);

        // If we didn't find a pivot,
        // then array is not rotated at all
        if (pivot == -1)
            return binarySearch(arr, 0, n - 1, key);

        // If we found a pivot, then first compare with pivot
        // and then search in two subarrays around pivot
        if (arr[pivot] == key)
            return pivot;

        if (arr[0] <= key)
            return binarySearch(arr, 0, pivot - 1, key);

        return binarySearch(arr, pivot + 1, n - 1, key);
    }
};
class betterSolution
{
public:
    int search(int arr[], int low, int high, int key)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return mid;
            else if (arr[low] <= arr[mid]) // checking if the left half is sorted or not?
            {
                //Checking if the key will lie on which side
                if (arr[mid] > key and arr[low] <= key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                //Similarly if the left half is not sorted then it means right half will be
        
                if (arr[mid] < key and arr[high] >= key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
}