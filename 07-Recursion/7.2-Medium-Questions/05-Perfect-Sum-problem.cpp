/*
Gfg:https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int count = 0;
    void helper(int arr[], int idx, int sum, int n, int target)
    {
        if (sum == target)
        {
            count++;
            return;
        }

        for (int i = idx; i < n; i++)
        {
            sum += arr[i];
            helper(arr, i + 1, sum, n, target);
            sum -= arr[i];
        }
    }
    int perfectSum(int arr[], int n, int sum)
    {
        helper(arr, 0, 0, n, sum);
        return count;
    }
};
int main()
{
}