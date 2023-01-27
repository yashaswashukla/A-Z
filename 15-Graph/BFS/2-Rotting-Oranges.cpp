/*
GFG: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({i, j});

        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            ans++;

            for (int i = 0; i < size; i++)
            {
                int x = q.front().first, y = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nrow = x + row[k];
                    int ncol = y + col[k];

                    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1)
                    {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        return ans - 1;
    }
};
int main()
{
}
