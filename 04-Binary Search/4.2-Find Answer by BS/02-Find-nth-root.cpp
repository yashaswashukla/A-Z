/*
GFG:https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        // Code here.
        int low = 1, high = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            double k = pow(mid, n);

            if (k == m)
                return mid;
            else if (k > m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};
int main()
{
}