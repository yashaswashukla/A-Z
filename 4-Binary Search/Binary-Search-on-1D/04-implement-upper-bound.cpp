/*
GFG:https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Question given in the striver sheet
public:
    pair<int, int> getFloorAndCeil(int arr[], int n, int x)
    {
        int floor = INT_MIN, ceil = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= x and arr[i] > floor)
                floor = arr[i];
            if (arr[i] >= x and arr[i] < ceil)
                ceil = arr[i];
        }

        floor = (floor == INT_MIN) ? -1 : floor;
        ceil = (ceil == INT_MAX) ? -1 : ceil;

        return {floor, ceil};
    }
};

// Real upper bound code
class upperSolution
{
    int findCeil(vector<long long> v, long long n, long long x)
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

        return low;
    }
};
int main()
{
}