/*
Link:https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category[]=Hash&category[]=Hash&company[]=Amazon&company[]=Amazon&page=1&query=category[]Hashcompany[]Amazonpage1company[]Amazoncategory[]Hash
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int maxLen(vector<int> &A, int n)
    {
        int ans = 0;
        vector<int> sum(n, 0);
        sum[0] = A[0];
        for (int i = 1; i < n; i++)
            sum[i] = A[i] + sum[i - 1];

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            if (!sum[i])
                ans = max(ans, i + 1);
            else if (hash.count(sum[i]))
                ans = max(ans, (i - hash[sum[i]]));
            else
                hash[sum[i]] = i;
        }
        return ans;
    }
};
int main()
{
}