/*
Gfg:https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?page=1&category[]=Disjoint%20Set&sortBy=submissions
Leetcode:https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; i++)
            adj[i][i] = 0;

        for (int via = 0; via < n; via++)
            for (int src = 0; src < n; src++)
                for (int dst = 0; dst < n; dst++)
                {
                    adj[src][dst] = min(adj[src][dst], adj[src][via] + adj[via][dst]);
                }

        int ans = -1, totalcount = INT_MAX;
        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int next = 0; next < n; next++)
                if (adj[city][next] <= distanceThreshold)
                    count++;
            if (count <= totalcount)
            {
                ans = city;
                totalcount = count;
            }
        }
        return ans;
    }
};
int main()
{
}