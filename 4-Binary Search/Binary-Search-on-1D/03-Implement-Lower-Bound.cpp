/*
GFG:https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x)
    {

        int ans = -1;
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < x or arr[mid] == x)
            {
                ans = mid;
                left = mid + 1;
            }
            else if (arr[mid] > x)
                right = mid - 1;
        }
        return ans;
    }
};
class anotherSolution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {

        // Your code here
        long long low = 0, high = n;

        while (low < high)
        {
            long long mid = (high + low) / 2;
            if (v[mid] > x)
                high = mid;
            else
                low = mid + 1;
        }

        return low - 1;
    }
};
int main()
{
}