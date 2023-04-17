/*
GFG: https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool Search(int n, vector<int> &arr, int key)
    {
        // Code here
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return 1;
            if ((arr[low] == arr[mid]) and (arr[high] == arr[mid]))
            {
                low++;
                high--;
            }
            else if (arr[mid] >= arr[low])
            {
                if (key < arr[mid] and key >= arr[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (key > arr[mid] and key <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return 0;
    }
};
int main()
{
}