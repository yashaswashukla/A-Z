/*
GFG: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=trapping-rain-water
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
/*
------------------------------Brute Force------------------------------
---> Simple approach to this question is to find the maximum building
---> to the left and to the right and then take the min of both and
---> subtract the curr height.
 */
class naiveSolution
{
public:
    long long trappingWater(int arr[], int n)
    {
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            int left = arr[i], right = arr[i];
            for (int j = i - 1; j >= 0; j--)
                if (arr[j] > left)
                    left = arr[j];
            for (int j = i + 1; j < n; j++)
                if (arr[j] > right)
                    right = arr[j];

            ans += min(left, right) - curr;
        }
        return ans;
    }
};

class betterSolution
{
public:
    long long trappingWater(int arr[], int n)
    {
        long long ans = 0;
        int prefix[n], suffix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], arr[i]);
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], arr[i]);

        for (int i = 0; i < n; i++)
            ans += min(prefix[i], suffix[i]) - arr[i];

        return ans;
    }
};

class bestSolution
{
public:
    long long trappingWater(int arr[], int n)
    {
        long long ans = 0;
    }
};
int main()
{
}