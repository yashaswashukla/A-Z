/*
Gfg:https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/1
Leetcode:https://leetcode.com/problems/largest-divisible-subset/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1), hash(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[i] % arr[prev] == 0 and dp[prev] + 1 > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > dp[maxi])
                maxi = i;
        }

        vector<int> ans;
        ans.push_back(arr[maxi]);
        while (hash[maxi] != maxi)
        {
            maxi = hash[maxi];
            ans.push_back(arr[maxi]);
        }
        return ans;
    }
};
int main()
{
}