/*
GFG:https://practice.geeksforgeeks.org/problems/bipartite-graph/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class dfsSolution
{
public:
    bool dfsBipartite(int node, vector<int> adj[], vector<int> &color, int c)
    {

        color[node] = c;

        for (auto x : adj[node])
        {
            if (color[x] == -1)
            {
                if (!dfsBipartite(x, adj, color, !c))
                    return false;
            }
            else if (color[x] == color[node])
                return false;
        }

        return true;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!dfsBipartite(i, adj, color, 1))
                    return false;
            }
        }
        return true;
    }
};
class bfsSolution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        queue<int> q;
        int prevColor = 0;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = prevColor;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (auto x : adj[node])
                    {
                        if (color[x] == -1)
                        {
                            color[x] = !color[node];
                            q.push(x);
                        }
                        if (color[x] == color[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
}