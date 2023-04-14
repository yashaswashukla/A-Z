/*
GFG: https://practice.geeksforgeeks.org/problems/smallest-divisor/1`
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(int mid, vector<int> &nums, int k)
    {
        int sum = 0;
        for (int k : nums)
            sum += ceil((double)k / mid);

        return sum <= k;
    }

public:
    int smallestDivisor(vector<int> &nums, int k)
    {
        int low = 1, high = INT_MIN;
        for (int x : nums)
            high = max(high, x);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, k))
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