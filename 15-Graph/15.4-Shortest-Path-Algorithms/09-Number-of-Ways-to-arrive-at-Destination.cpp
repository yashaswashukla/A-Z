/*
Gfg:https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
Leetcode:https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dis(n, LONG_MAX);
        vector<int> ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        set<pair<long long, int>> hash;
        hash.insert({0, 0});

        while (!hash.empty())
        {
            auto it = *(hash.begin());
            hash.erase(it);

            long long cost = it.first;
            int node = it.second;

            for (auto x : adj[node])
            {
                long long next = x.first, totalCost = cost + x.second;
                if (dis[next] > totalCost)
                {
                    if (dis[next] != LONG_MAX)
                        hash.erase({dis[next], next});
                    dis[next] = totalCost % mod;
                    ways[next] = ways[node] % mod;
                    hash.insert({dis[next], next});
                }
                else if (dis[next] == totalCost)
                    ways[next] = (ways[node] % mod + ways[next] % mod) % mod;
            }
        }
        return ways[n - 1];
    }
};
int main()
{
}