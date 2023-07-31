/*
Gfg:https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int V = matrix.size();
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;
                if (i == j)
                    matrix[i][j] = 0;
            }

        for (int via = 0; via < V; via++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
    }
    bool detectnegativeCycle(vector<vector<int>> &matrix)
    {
        int V = matrix.size();
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;
                if (i == j)
                    matrix[i][j] = 0;
            }

        for (int via = 0; via < V; via++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    // because if a negative weight cycle exists then the cost of reaching the node from the same node
                    // can be lesser than 0 and hence it will be safe to say that negative weight cycle exists.
                    if (i == j and matrix[i][j] < 0)
                        return true;
                }
    }
};
int main()
{
}