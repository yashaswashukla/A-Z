/*
GFG:https://practice.geeksforgeeks.org/problems/make-zeroes4042/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class gfgSolution
{
private:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};

public:
    void MakeZeros(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> temp(matrix);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!temp[i][j])
                {
                    int sum = 0;

                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = i + x[k], ncol = j + y[k];

                        if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m)
                        {
                            sum += temp[nrow][ncol];
                            matrix[nrow][ncol] = 0;
                        }
                    }
                    matrix[i][j] = sum;
                }
            }
        }
    }
};
class leetcodeSolution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    if (j)
                        matrix[0][j] = 0;
                    else
                        col0 = 1;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j])
                {
                    if (!matrix[0][j] or !matrix[i][0])
                        matrix[i][j] = 0;
                }
            }
        }

        if (!matrix[0][0])
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;

        if (col0)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};
int main()
{
}