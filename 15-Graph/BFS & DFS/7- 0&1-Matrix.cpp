/*
GFG:https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    bool check(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        return true;
    }

    int row[4] = {1, 0, -1, 0};
    int col[4] = {0, 1, 0, -1};

    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nrow = x + row[k];
                    int ncol = y + col[k];

                    if (check(nrow, ncol, n, m) and ans[nrow][ncol] == -1)
                    {
                        ans[nrow][ncol] = ans[x][y] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return ans;
    }
};
int main()
{
}