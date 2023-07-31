/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
    vector<int> parent, size;

public:
    disjointSet(int n)
    {
        size.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void combine(int x, int y)
    {
        int par_x = findparent(x), par_y = findparent(y);
        if (par_x == par_y)
            return;
        if (size[par_x] > size[par_y])
        {
            parent[par_y] = par_x;
            size[par_x] += size[par_y];
        }
        else
        {
            parent[par_x] = par_y;
            size[par_y] += size[par_x];
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        disjointSet dsj(V);
        vector<pair<int, pair<int, int>>> edge;
        for (int i = 0; i < V; i++)
            for (auto it : adj[V])
            {
                int node = i, child = it[0], weight = it[1];
                edge.push_back({weight, {node, child}});
            }
        sort(edge.begin(), edge.end());

        int total_weight = 0;
        for (auto it : edge)
        {
            int cost = it.first, node = it.second.first, child = it.second.second;

            if (dsj.findparent(node) != dsj.findparent(child))
            {
                total_weight += cost;
                dsj.combine(node, child);
            }
        }
        return total_weight;
    }
};
int main()
{
}