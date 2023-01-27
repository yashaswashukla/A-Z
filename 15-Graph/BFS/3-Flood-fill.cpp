/*
GFG: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    void dfs(int sr, int sc, vector<vector<int>> &image, int newColor, int prevColor)
    {
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + row[i];
            int ncol = sc + col[i];

            if (nrow >= 0 and nrow < image.size() and ncol >= 0 and ncol < image[0].size())
                if (image[nrow][ncol] == prevColor)
                    dfs(nrow, ncol, image, newColor, prevColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int prevColor = image[sr][sc];

        dfs(sr, sc, image, newColor, prevColor);
    }
};
int main()
{
}