/*
Gfg:https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        set<pair<int, int>> hash;
        dis[1] = 0;
        hash.insert({0, 1});
        while (!hash.empty())
        {
            auto it = *(hash.begin());
            int curr = it.first, node = it.second;
            hash.erase(it);

            for (auto items : adj[node])
            {
                int child = items.first, edgeWeight = items.second;
                if (dis[child] > edgeWeight + curr)
                {
                    if (dis[child] != -1)
                        hash.erase({dis[child], child});
                    dis[child] = edgeWeight + curr;
                    hash.insert({dis[child], child});
                    parent[child] = node;
                }
            }
        }
        vector<int> ans;
        if (dis[n] == 1e9)
            return {-1};
        int node = n;
        while (parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}