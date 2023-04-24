/*
GFG: https://practice.geeksforgeeks.org/problems/square-root/0
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long int floorSqrt(long long int x)
    {
        long long low = 0, high = x;

        while (low < high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid <= x)
                low = mid + 1;
            else
                high = mid;
        }
        return low - 1;
    }
};
int main()
{
}