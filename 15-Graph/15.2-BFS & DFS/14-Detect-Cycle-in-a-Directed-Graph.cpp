/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class dfsSolution
{
public:
    // Function to detect cycle in a directed graph.
    bool cyclicDfs(int i, vector<int> adj[], vector<int> &visited, vector<int> &dfsvis)
    {
        visited[i] = 1;
        dfsvis[i] = 1;

        for (auto x : adj[i])
        {
            if (!visited[x])
            {
                if (cyclicDfs(x, adj, visited, dfsvis))
                    return true;
            }
            else if (dfsvis[x])
                return true;
        }

        dfsvis[i] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {

        vector<int> visited(V, 0);
        vector<int> dfsvis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cyclicDfs(i, adj, visited, dfsvis))
                    return true;
        }

        return false;
    }
};
class bfsSolution // Kahn's Algorithm (Topological Sort)
{
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int ans = 0;
        queue<int> q;

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
                inDegree[x]++;
        }

        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans++;

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }

        return (ans != V);
    }
};
int main()
{
}