/*
Gfg:https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
Leetcode:https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});
        vector<int> dis(n, 1e9);
        set<pair<int, pair<int, int>>> hash;
        hash.insert({0, {src, 0}});
        dis[src] = 0;

        while (!hash.empty())
        {
            auto it = *(hash.begin());
            hash.erase(it);
            int stops = it.first, node = it.second.first, cost = it.second.second;

            if (stops > K)
                break;

            for (auto x : adj[node])
            {
                int next = x.first, price = x.second;
                if (dis[next] > price + cost and stops <= K)
                {
                    dis[next] = price + cost;
                    hash.insert({stops + 1, {next, dis[next]}});
                }
            }
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};
int main()
{
}