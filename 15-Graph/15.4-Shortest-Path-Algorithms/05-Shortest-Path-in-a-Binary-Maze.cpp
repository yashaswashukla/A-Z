/*
Gfg:
Leetcode:https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/
#include <bits/stdc++.h>
using namespace std;
class leetSolution
{
public:
    int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
    int y[8] = {1, -1, 0, 1, -1, 0, 1, -1};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            ans++;
            while (size--)
            {
                int row = q.front().first, col = q.front().second;
                q.pop();
                if (row == n - 1 and col == n - 1)
                    return ans;

                for (int i = 0; i < 8; i++)
                {
                    int nrow = row + x[i], ncol = col + y[i];
                    if (nrow < n and nrow >= 0 and ncol < n and ncol >= 0 and !grid[nrow][ncol])
                    {
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
class geekSolution
{
public:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (!A[0][0] or !A[X][Y])
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            ans++;
            while (size--)
            {
                int row = q.front().first, col = q.front().second;
                q.pop();
                if (row == X and col == Y)
                    return ans - 1;

                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + x[i], ncol = col + y[i];
                    if (nrow < N and ncol < M and ncol >= 0 and nrow >= 0 and A[nrow][ncol])
                    {
                        A[nrow][ncol] = 0;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
int main()
{
}