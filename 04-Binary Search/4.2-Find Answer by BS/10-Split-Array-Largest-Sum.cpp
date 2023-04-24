/*
GFG: https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool check(long long int mid, long long int a[], long long int n, long long int k)
    {
        long long sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum > mid)
            {
                count++;
                sum = a[i];
            }
        }
        return count <= k;
    }
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        long long int low = a[0], high = 0;

        for (int i = 0; i < n; i++)
        {
            low = max(low, a[i]);
            high += a[i];
        }
        int ans = -1;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;

            if (check(mid, a, n, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
class Solution
{
private:
    bool check(int mid, vector<int> &nums, int k)
    {
        int sum = 0, count = 0;
        for (auto x : nums)
        {
            sum += x;
            if (sum > mid)
            {
                count++;
                sum = x;
            }
        }
        return count >= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = 0, high = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (!check(mid, nums, k))
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