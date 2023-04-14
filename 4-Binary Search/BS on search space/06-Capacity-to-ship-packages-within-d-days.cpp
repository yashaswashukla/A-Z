/*
GFG: https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(int mid, int arr[], int n, int day)
    {
        int total = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                total++;
                sum = 0;
            }
        }
        total++;
        return total <= day;
    }

public:
    int leastWeightCapacity(int arr[], int N, int D)
    {
        int low = 0, high = 0;
        for (int i = 0; i < N; i++)
        {
            high += arr[i];
            low = max(low, arr[i]);
        }

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (check(mid, arr, N, D))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
int main()
{
}