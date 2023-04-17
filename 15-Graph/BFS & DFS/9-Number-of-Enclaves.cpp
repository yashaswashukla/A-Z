/*
GFG: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    void dfs(int i, int j, int n, int m, vector<vector<int>> &mat)
    {
        mat[i][j] = 2;
        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k];
            int ncol = j + col[k];

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m)
                if (mat[nrow][ncol] == 1)
                    dfs(nrow, ncol, n, m, mat);
        }
    }

    int numberOfEnclaves(vector<vector<int>> &mat)
    {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1)
                    if (mat[i][j] == 1)
                        dfs(i, j, n, m, mat);

                if (j == 0 || j == m - 1)
                    if (mat[i][j] == 1)
                        dfs(i, j, n, m, mat);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
int main()
{
}