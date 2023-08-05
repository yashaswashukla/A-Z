/*
Gfg:https://practice.geeksforgeeks.org/problems/number-of-islands/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }
    int join(vector<int> &parent, int x, int y)
    {
        parent[find(parent, x)] = find(parent, y);
    }
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<int> parent(n * m);
        for (int i = 0; i < n * m; i++)
            parent[i] = i;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        int count = 0;
        for (auto it : operators)
        {
            int row = it[0], col = it[1];
            if (vis[row][col])
            {
                ans.push_back(count);
                continue;
            }
            vis[row][col] = 1;
            count++;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dir[i].first, ncol = col + dir[i].second;
                if (nrow >= n or nrow < 0 or ncol >= m or ncol < 0)
                    continue;
                if (!vis[nrow][ncol])
                    continue;

                int old = row * m + col, nw = nrow * m + ncol;
                if (find(parent, old) != find(parent, nw))
                {
                    count--;
                    join(parent, old, nw);
                }
            }
            ans.push_back(count);
        }
    }
};
int main()
{
}