/*
GFG:https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/0?company[]=Visa&company[]=Visa&page=2&query=company[]Visapage2company[]Visa
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxsum = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxsum = max(sum, maxsum);

            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
};
int main()
{
}