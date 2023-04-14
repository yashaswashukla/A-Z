/*
GFG:https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
Leetcode: https://leetcode.com/problems/number-of-provinces/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> &vis, vector<vector<int>> &adj, int i)
    {
        vis[i] = 1;

        for (int k = 0; k < adj[i].size(); k++)
            if (adj[i][k] and !vis[k])
                dfs(vis, adj, k);
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> vis(V);
        int ans = 0;

        for (int i = 0; i < V; i++)
            if (!vis[i])
                ans++, dfs(vis, adj, i);
        return ans;
    }
};
int main()
{
}