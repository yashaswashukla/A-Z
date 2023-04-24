/*
GFG: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class bfsSolution
{
    /*
    Intution:

    Terminal node: No outgoing edge outdegree = 0,
    If we reverse the edges then indegree = 0 and then we can apply
    Kahn's algorithm and find out the remaining nodes which are not part
    of a cycle. Because if a node is a part of a cycle then there will always be a path
    which will not lead to the terminal node.

    Why?

    As terminal node has no outgoing edge then it can not be a part of a cycle
    Hence, all the nodes present in the cycle will be non-terminal.

    Can a node not be a non-safe node if it does not contain any cycle?

    NO, Because if the node is not part of any cycle or has an outgoing edge towards a cycle,
    then all of it's path will lead to a node at which the path ends and that node will be
    terminal in it self.

     */
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> newadj[V];
        vector<int> inDegree(V, 0);
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < V; i++)
            for (auto x : adj[i])
            {
                newadj[x].push_back(i);
                inDegree[i]++;
            }

        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto x : newadj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class dfsSolution
{
    /*
    Similar logic, We only have to find all the nodes with cycle or have an outgoing edge
    to a cycle, that can also be found out by finding the cycle in a directed graph
    using dfs.
    
    Here, we will not have to reverse the edges of the graph
    */
private:
    bool dfs(int node, vector<int> &vis, vector<int> &cycle, vector<int> adj[])
    {
        vis[node] = 2;

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                if (dfs(x, vis, cycle, adj))
                {
                    cycle[x] = 1;
                    return true;
                }
            }
            else if (vis[x] == 2)
            {
                cycle[x] = 1;
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> cycle(V, 0);
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
            if (!vis[i])
                if (dfs(i, vis, cycle, adj))
                    cycle[i] = 1;

        vector<int> ans;

        for (int i = 0; i < V; i++)
            if (!cycle[i])
                ans.push_back(i);
        return ans;
    }
};
int main()
{
}