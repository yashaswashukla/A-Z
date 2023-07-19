/*
Gfg:https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LongestBitonicSequence(vector<int> nums)
    {
        int n = nums.size();
        vector<int> inc(n, 1), dec(n, 1);

        // For the longest increasing subsequence at every index
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] and inc[j] + 1 > inc[i])
                    inc[i] = inc[j] + 1;

        // For the longest decreasing subsequence at every index, which is also
        // longest increasing subsequence when viewed from the right;

        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j > i; j--)
                if (nums[i] > nums[j] and dec[i] < dec[j] + 1)
                    dec[i] = dec[j] + 1;

        // Now finding the length of the longest bitonic which will be combination of
        // longest increasing and decreasing subsequences

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, inc[i] + dec[i]);

        // Why -1? Because we had calculated increasing and decreasing subsequence till every index
        // which contains the index itself, now when we add both of them we include the index twice
        // Hence, subtracting 1 from the total answer;
        return ans - 1;
    }
};
int main()
{
}