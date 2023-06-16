/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/0?qa-rewrite=3336/print-all-valid-combinations-of-ip-address&show=3350
Leetcode:https://leetcode.com/problems/maximum-product-subarray/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long maxProduct(vector<int> arr, int n)
    {
        long long left = arr[0], right = arr[0];
        long long prod = 1;
        bool zero = false;
        for (int i = 0; i < n; i++)
        {
            prod *= arr[i];
            if (!arr[i])
            {
                prod = 1;
                zero = true;
                continue;
            }
            left = max(left, prod);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            prod *= arr[i];
            if (!arr[i])
            {
                zero = true;
                prod = 1;
                continue
            }
            right = max(right, prod);
        }

        if (zero)
            return max(max(left, right), 0);
        return max(left, right);
    }
};
int main()
{
}