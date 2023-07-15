/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> longestSubseqeunce(int n, int arr[])
    {
        vector<int> ans;
        vector<int> dp(n, 1), hash(n, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i])
                    if (dp[prev] + 1 > dp[i])
                    {
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
            }
            if (dp[i] > dp[maxi])
                maxi = i;
        }
        while (hash[maxi] != maxi)
        {
            ans.push_back(arr[maxi]);
            maxi = hash[maxi];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}