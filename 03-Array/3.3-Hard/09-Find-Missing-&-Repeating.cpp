/*
Gfg:https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        long long cursum = 0, actsum = ((long long)n * (long long)(n + 1)) / 2;
        for (auto x : arr)
            cursum += (long long)x;
        long long sqcursum = 0, sqactsum = ((long long)n * (long long)(n + 1) * (long long)(2 * n + 1)) / 6;
        for (auto x : arr)
            sqcursum += (long long)x * (long long)x;
        long long diff = cursum - actsum, sqdiff = sqcursum - sqactsum;
        long long sum = sqdiff / diff;

        long long repeating = (sum + diff) / 2;
        long long missing = sum - repeating;
        return {(int)repeating, (int)missing};
    }
};
int main()
{
}