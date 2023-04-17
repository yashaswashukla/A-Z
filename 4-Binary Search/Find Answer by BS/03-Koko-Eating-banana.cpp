/*
GFG:https://practice.geeksforgeeks.org/problems/koko-eating-bananas/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool eat(int mid, int H, vector<int> &piles)
    {
        int total = 0;

        for (auto ban : piles)
        {
            if (ban % mid)
                total += ban / mid + 1;
            else
                total += ban / mid;
        }

        return (total <= H) ? true : false;
    }
    int Solve(int N, vector<int> &piles, int H)
    {
        // Code here
        int low = 1, high = INT_MIN;

        for (auto ban : piles)
            high = max(ban, high);

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (eat(mid, H, piles))
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }
};
int main()
{
}