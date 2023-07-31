/*
Gfg:https://practice.geeksforgeeks.org/problems/union-find/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void union_(int a, int b, int par[], int rank1[])
    {
        int par_a = find(par, a), par_b = find(par, b);
        if (rank1[par_a] > rank1[par_b])
        {
            par[par_b] = par_a;
            rank1[par_a] += rank1[par_b];
        }
        else
        {
            par[par_a] = par_b;
            rank1[par_b] += rank1[par_a];
        }
    }
    int find(int par[], int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par, par[x]);
    }
    bool isConnected(int x, int y, int par[], int rank1[])
    {
        int parent_x = find(par, x);
        int parent_y = find(par, y);
        return parent_x == parent_y;
    }
};
int main()
{
}