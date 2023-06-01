/*
GFG:https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int lenOfLongSubarr(int A[], int N, int K)
    {
        unordered_map<int, int> hash;

        int sum = 0, ans = 0;

        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum == K)
                ans = max(ans, i + 1);
            if (hash.find(sum) == hash.end())
                hash[sum] = i;

            if (hash.find(sum - K) != hash.end())
                ans = max(ans, i - hash[sum - K]);
        }
        return ans;
    }
};
int main()
{
}