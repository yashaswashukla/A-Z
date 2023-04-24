/*
GFG:https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int mid, vector<int> &bloomDay, int k, int m)
    {
        int subarray = 0;
        int count = 0;

        for (auto x : bloomDay)
        {
            if (x <= mid)
            {
                count++;
                if (count == k)
                {
                    subarray++;
                    count = 0;
                }
            }
            else
                count = 0;
        }

        return (subarray >= m) ? true : false;
    }
    int solve(int M, int K, vector<int> &bloomDay)
    {
        // Code here
        if (bloomDay.size() < M * K)
            return -1;

        int low = 1, high = INT_MIN;

        for (auto day : bloomDay)
            high = max(high, day);

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (check(mid, bloomDay, K, M))
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