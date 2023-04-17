/*
GFG: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V, vector<int> adj[], vector<int> &answer, vector<int> &visited)
    {
        visited[V] = 1;
        answer.push_back(V);
        for (auto x : adj[V])
        {
            if (visited[x] == 0)
                dfs(x, adj, answer, visited);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> answer;
        vector<int> visited(V, 0);
        dfs(0, adj, answer, visited);
        return answer;
    }
};
int main()
{
}