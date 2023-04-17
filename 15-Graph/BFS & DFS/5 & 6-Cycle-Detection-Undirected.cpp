/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class bfsSolution
{
public:
    // Function to detect cycle in an undirected graph.
    bool cyclicBfs(int i, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> que;

        que.push({i, -1});
        visited[i] = 1;

        while (!que.empty())
        {

            int node = que.front().first;
            int parent = que.front().second;

            que.pop();

            for (auto x : adj[node])
            {
                // cout<<x<<" ";
                if (!visited[x])
                {
                    visited[x] = 1;
                    que.push({x, node});
                }
                else
                {

                    if (x != parent)
                        return true;
                }
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 1; i < V; i++)
        {
            if (!visited[i])
                if (cyclicBfs(i, adj, visited))
                    return true;
        }

        return false;
    }
};
class dfsSolution
{
public:
    // Function to detect cycle in an undirected graph.
    bool cyclicDfs(int i, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[i] = 1;

        for (auto x : adj[i])
        {
            if (!visited[x])
            {
                if (cyclicDfs(x, i, adj, visited))
                    return true;
            }
            else
            {
                if (x != parent)
                    return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cyclicDfs(i, -1, adj, visited))
                    return true;
        }

        return false;
    }
};
int main()
{
}