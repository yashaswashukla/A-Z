/*
Gfg: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> ans(N, -1);
        vector<int> adj[N];
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        ans[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            int distance = ans[node];

            for (auto child : adj[node])
                if (ans[child] == -1)
                {
                    ans[child] = distance + 1;
                    q.push(child);
                }
        }
        return ans;
    }
};
int main()
{
}