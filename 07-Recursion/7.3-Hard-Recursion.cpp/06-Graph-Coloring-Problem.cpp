/*
Gfg:https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(bool graph[101][101], int color[], int n, int node, int currcolor)
    {
        for (int i = 0; i < n; i++)
            if (i != node and graph[node][i] and color[i] == currcolor)
                return false;
        return true;
    }
    bool solve(bool graph[101][101], int m, int n, int color[], int node)
    {
        if (node >= n)
            return true;

        for (int i = 1; i <= m; i++)
        {
            if (check(graph, color, n, node, i))
            {
                color[node] = i;
                if (solve(graph, m, n, color, node + 1))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        int color[n] = {0};
        return solve(graph, m, n, color, 0);
    }
};
int main()
{
}