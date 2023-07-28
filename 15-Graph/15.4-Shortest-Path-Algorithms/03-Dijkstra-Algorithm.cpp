/*
Gfg:https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using a queue and an array
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, 1e9);
        unordered_set<int> vis;
        ans[S] = 0;
        queue<int> q;
        q.push(S);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis.insert(node);
            int dis = ans[node];
            for (auto it : adj[node])
            {
                int child = it[0], edgeWeight = it[1];
                if (ans[child] > dis + edgeWeight)
                {
                    q.push(child);
                    ans[child] = dis + edgeWeight;
                }
            }
        }
        return ans;
    }
    // Using Priority Queue
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, 1e9);
        ans[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, S});
        while (!q.empty())
        {
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int child = it[0];
                if (ans[child] > distance + edgeWeight)
                {
                    ans[child] = distance + edgeWeight;
                    q.push({ans[child], child});
                }
            }
        }
        return ans;
    }
    // Using Set because in set we can remove the previous value of any node which might be present
    // But in priority queue we had to iterate which takes some extra time but the set won't
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V, 1e9);
        ans[S] = 0;
        set<pair<int, int>> hash;
        hash.insert({0, S});

        while (!hash.empty())
        {
            auto it = *(hash.begin());
            int distance = it.first, node = it.second;
            hash.erase(it);

            for (auto it : adj[node])
            {
                int child = it[0], edgeWeight = it[1];
                if (ans[child] > edgeWeight + distance)
                {
                    if (ans[child] != 1e9)
                        hash.erase({ans[child], child});
                    ans[child] = edgeWeight + distance;
                    hash.insert({ans[child], child});
                }
            }
        }
        return ans;
    }
};
int main()
{
}