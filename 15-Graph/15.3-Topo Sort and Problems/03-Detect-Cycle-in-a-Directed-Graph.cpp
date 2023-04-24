/*
GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class dfsSolution
{
private:
    bool dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i] = 2;

        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                if (dfs(x, adj, vis))
                    return true;
            }
            else if (vis[x] == 2)
                return true;
        }
        vis[i] = 1;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (dfs(i, adj, vis))
                    return true;
        return false;
    }
};
class bfsSolution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        queue<int> q;
        for (int i = 0; i < V; i++)
            for (auto x : adj[i])
                inDegree[x]++;
        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);
        int i = 0;
        while (!q.empty())
        {
            int node = q.front();
            i++;
            q.pop();Z$Z

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        if (i != V)
            return true;
        return false;
    }
};
int main()
{
}