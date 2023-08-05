/*
Gfg:https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
Leetcode:https://leetcode.com/problems/making-a-large-island/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> parent;
    vector<int> size;
    pair<int, int> dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool isValid(int row, int col, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (row < n and col < n and row >= 0 and col >= 0 and grid[row][col])
            return true;
        return false;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void join(int a, int b)
    {
        int para = find(a), parb = find(b);
        if (para == parb)
            return;
        if (size[para] > size[parb])
        {
            parent[parb] = para;
            size[para] += size[parb];
        }
        else
        {
            parent[para] = parb;
            size[parb] += size[para];
        }
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        parent.resize(n * n + 1);
        size.resize(n * n + 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i, size[i] = 1;

        // Connect all the available 1s

        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
            {
                if (!grid[row][col])
                    continue;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dir[i].first, ncol = col + dir[i].second;
                    if (isValid(nrow, ncol, grid))
                    {
                        int oldco = row * n + col, newco = nrow * n + ncol;
                        join(oldco, newco);
                    }
                }
            }

        int maxi = 0;
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col])
                    continue;
                set<int> hash;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dir[i].first, ncol = col + dir[i].second;
                    if (isValid(nrow, ncol, grid))
                        hash.insert(find(nrow * n + ncol));
                }
                int totalsize = 0;
                for (auto it : hash)
                    totalsize += size[it];
                maxi = max(maxi, totalsize + 1);
            }

        for (int i = 0; i < n * n; i++)
            maxi = max(maxi, size[i]);
        return maxi;
    }
};
class geekSolution
{
public:
    vector<int> parent;
    vector<int> size;
    pair<int, int> dir[8] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool isValid(int row, int col, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (row < n and col < m and row >= 0 and col >= 0 and grid[row][col])
            return true;
        return false;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void join(int a, int b)
    {
        int para = find(a), parb = find(b);
        if (para == parb)
            return;
        if (size[para] > size[parb])
        {
            parent[parb] = para;
            size[para] += size[parb];
        }
        else
        {
            parent[para] = parb;
            size[parb] += size[para];
        }
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        parent.resize(n * m + 1);
        size.resize(n * m + 1);

        for (int i = 0; i < n * m; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    size[i * m + j] = 1;

        // Connect all the available 1s

        for (int row = 0; row < n; row++)
            for (int col = 0; col < m; col++)
            {
                if (!grid[row][col])
                    continue;
                for (int i = 0; i < 8; i++)
                {
                    int nrow = row + dir[i].first, ncol = col + dir[i].second;
                    if (isValid(nrow, ncol, grid))
                    {
                        int oldco = row * m + col, newco = nrow * m + ncol;
                        join(oldco, newco);
                    }
                }
            }
        int ans = 0;
        for (int i = 0; i < n * m; i++)
            ans = max(ans, size[i]);
        return ans;
    }
};

int main()
{
}