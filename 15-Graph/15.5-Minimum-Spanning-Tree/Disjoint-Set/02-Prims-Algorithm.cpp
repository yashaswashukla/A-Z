/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
#define pll pair<int, pair<int, int>>
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, {0, -1}});
        int sum = 0;
        vector<int> vis(V, 0);
        vector<pair<int, int>> MST;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int cost = temp.first, node = temp.second.first, parent = temp.second.second;

            if (vis[node])
                continue;
            vis[node] = 1;
            if (parent != -1)
            {
                sum += cost;
                MST.push_back({parent, node});
            }

            for (auto it : adj[node])
            {
                int child = it[0], price = it[1];
                if (!vis[child])
                    pq.push({price, {child, node}});
            }
        }
        return sum;
    }
};
int main()
{
}