/*
GFG:https://practice.geeksforgeeks.org/problems/topological-sort/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class bfsSolution // Kahn's Algorithm
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < V; i++)
            for (auto x : adj[i])
                inDegree[x]++;

        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        return ans;
    }
};
class dfsSolution
{
private:
    void dfs(int i, vector<int> adj[], stack<int> &st, vector<int> &vis)
    {
        vis[i] = 1;
        for (auto x : adj[i])
            if (!vis[x])
                dfs(x, adj, st, vis);
        st.push(i);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < V; i++)
            if (!vis[i])
                dfs(i, adj, st, vis);

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
int main()
{
}