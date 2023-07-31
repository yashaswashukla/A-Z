/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 100000;
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        int steps = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (node == end)
                return steps;
            for (auto it : arr)
            {
                int num = (it * node) % mod;

                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
int main()
{
}