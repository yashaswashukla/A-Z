/*
GFG:https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category=
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes
        long long ans = INT_MIN, sum = 0;
        for (int i = 0; i < N - 1; i++)
        {
            sum = arr[i] + arr[i + 1];
            ans = max(sum, ans);
        }
        return ans;
    }
};
int main()
{
}