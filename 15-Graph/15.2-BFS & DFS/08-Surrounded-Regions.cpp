/*
GFG: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    void dfs(int i, int j, int n, int m, vector<vector<char>> &mat)
    {
        mat[i][j] = '*';
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k];
            int ncol = j + col[k];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m)
                if (mat[nrow][ncol] == 'O')
                    dfs(nrow, ncol, n, m, mat);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1)
                    if (mat[i][j] == 'O')
                        dfs(i, j, n, m, mat);

                if (j == 0 || j == m - 1)
                    if (mat[i][j] == 'O')
                        dfs(i, j, n, m, mat);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '*')
                    mat[i][j] = 'O';
                else if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};
int main()
{
}