/*
Gfg:https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    string dir[4] = {"D", "U", "R", "L"};

    void dfs(int i, int j, int n, string temp, vector<string> &ans, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(temp);
            return;
        }
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k], ncol = j + col[k];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < n and !vis[nrow][ncol] and grid[nrow][ncol])
                dfs(nrow, ncol, n, temp + dir[k], ans, vis, grid);
        }
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if (!m[0][0] or !m[n - 1][n - 1])
            return {};
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vector<string> ans;
        dfs(0, 0, n, "", ans, vis, m);
        return ans;
    }
};
int main()
{
}