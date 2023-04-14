/*
GFG:https://practice.geeksforgeeks.org/problems/sum-of-subarray-ranges/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sum-of-subarray-ranges
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

/*
---> Iterate over sub-arrays and find the min and max and subtract them and add them.

TC: O(n^2) and SC: O(1)
*/
class naiveSolution
{
public:
    long long subarrayRanges(int N, vector<int> &arr)
    {
        long long ans = 0;
        for (int i = 0; i < N - 1; i++)
        {
            int ma = arr[i], mi = arr[i];
            for (int j = i + 1; j < N; j++)
            {
                ma = max(arr[j], ma);
                mi = min(arr[j], mi);
                ans += (ma - mi);
            }
        }
        return ans;
    }
};
/*
---> This question is based on a similar concept of finding the maximum subarray sum
---> and finding the minimum subarray sum and subtracting both of them.
*/
class betterSolution
{
public:
    long long subarrayRanges(int N, vector<int> &arr)
    {
        stack<int> inc;
        stack<int> dec;
        long long ans = 0;

        for (int i = 0; i <= N; i++)
        {
            while (!inc.empty() and (i == N or arr[inc.top()] < arr[i]))
            {
                int cur = inc.top();
                inc.pop();

                int left = inc.empty() ? -1 : inc.top();
                int right = i;
                ans += (long)(cur - left) * (right - cur) * arr[cur];
            }
            while (!dec.empty() and (i == N or arr[dec.top()] > arr[i]))
            {
                int cur = dec.top();
                dec.pop();
                int left = dec.empty() ? -1 : dec.top();
                int right = i;
                ans -= (long)(cur - left) * (right - cur) * arr[cur];
            }
            inc.push(i);
            dec.push(i);
        }

        return ans;
    }
};
int main()
{
}