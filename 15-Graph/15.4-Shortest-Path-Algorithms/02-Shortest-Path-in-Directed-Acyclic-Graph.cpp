/*
Gfg:https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
        This question can be solved using Dijkstra but here we try something different, we first find out the
        TopoSort of the graph which will give us a sequential order of the nodes, and we can start from the source
        assigning it 0 and then starting from there assigning it's adjacent nodes their corresponding values

        This approach helps us solve the question in O(N + M) time complexity where Dijkstra takes atleast O(N + M * Log N)
    */
    void dfs(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto child : adj[node])
            if (!vis[child.first])
                dfs(child.first, vis, adj, st);
        st.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<int> ans(N, 1e9);
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
            if (!vis[i])
                dfs(i, vis, adj, st);

        ans[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            int dis = ans[node];

            for (auto child : adj[node])
            {
                if (ans[child.first] > dis + child.second)
                    ans[child.first] = dis + child.second;
            }
        }
        for (auto &dis : ans)
            dis = dis == 1e9 ? -1 : dis;
        return ans;
    }
};
int main()
{
}