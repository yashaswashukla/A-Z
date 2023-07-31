/*
Gfg:https://practice.geeksforgeeks.org/problems/connecting-the-graph/1
Leetcode:https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find(vector<int> &parent, int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent, parent[a]);
    }
    void join(vector<int> &parent, int par_a, int par_b)
    {
        parent[par_a] = par_b;
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int extra = 0;
        for (auto it : connections)
        {
            int a = it[0], b = it[1];
            int par_a = find(parent, a), par_b = find(parent, b);
            if (par_a == par_b)
            {
                extra++;
                continue;
            }
            join(parent, par_a, par_b);
        }
        int comp = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                comp++;
        return comp - 1 <= extra ? comp - 1 : -1;
    }
};
int main()
{
}