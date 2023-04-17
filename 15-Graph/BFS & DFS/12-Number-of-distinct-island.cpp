/*
GFG:https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool is_safe(vector<vector<int>> &grid, int i, int j, string &v)
    {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0 && grid[i][j] != 0)
            return true;

        v.push_back('E');
        return false;
    }
    void solve(vector<vector<int>> &grid, int i, int j, string &v)
    {
        grid[i][j] = 0;

        if (is_safe(grid, i + 1, j, v))
        {
            v.push_back('D');
            solve(grid, i + 1, j, v);
        }
        if (is_safe(grid, i - 1, j, v))
        {
            v.push_back('U');
            solve(grid, i - 1, j, v);
        }
        if (is_safe(grid, i, j + 1, v))
        {
            v.push_back('R');
            solve(grid, i, j + 1, v);
        }
        if (is_safe(grid, i, j - 1, v))
        {
            v.push_back('L');
            solve(grid, i, j - 1, v);
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        unordered_set<string> st;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    string v;
                    v.push_back('S');
                    solve(grid, i, j, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
int main()
{
}