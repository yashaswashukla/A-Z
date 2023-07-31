/*
Gfg:https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(V, 1e8);
        dis[S] = 0;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0], v = edges[j][1], cost = edges[j][2];
                if (dis[u] + cost < dis[v])
                    dis[v] = dis[u] + cost;
            }
        bool negcycle = false;
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0], v = edges[j][1], cost = edges[j][2];
            if (dis[u] + cost < dis[v])
                return {-1};
        }
        return dis;
    }
};
int main()
{
}