/*
GFG: https://practice.geeksforgeeks.org/problems/aggressive-cows/1https://practice.geeksforgeeks.org/problems/aggressive-cows/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(int mid, vector<int> &stalls, int k)
    {
        int cows = 1, last = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if ((stalls[i] - last) >= mid)
            {
                cows++;
                last = stalls[i];
            }
        }
        return cows >= k;
    }

public:
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (!check(mid, stalls, k)) // Important, Why?
                high = mid;
            else
                low = mid + 1;
        }
        return high - 1;
    }
};

// In this question we have to maximise the minimum distance and hence if we found any distance at which we are able to
// place the cows we will again now find the value which will be greater that the previous value.
// Hence if the function returns false we reduce the value and look for smaller value else we go for finding bigger values.
int main()
{
}