/*
Gfg:https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
Leetcode:https://leetcode.com/problems/path-with-minimum-effort/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        set<vector<int>> hash;
        dis[0][0] = 0;
        hash.insert({0, 0, 0});
        while (!hash.empty())
        {
            vector<int> temp = *(hash.begin());
            hash.erase(temp);
            int currdiff = temp[0];
            int row = temp[1], col = temp[2];

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dir[i].first, ncol = col + dir[i].second;
                if (nrow < n and ncol < m and ncol >= 0 and nrow >= 0)
                {
                    int diff = abs(heights[row][col] - heights[nrow][ncol]);
                    diff = max(diff, currdiff);
                    if (diff < dis[nrow][ncol])
                    {
                        if (dis[nrow][ncol] != 1e9)
                            hash.erase({dis[nrow][ncol], nrow, ncol});
                        dis[nrow][ncol] = diff;
                        hash.insert({diff, nrow, ncol});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
int main()
{
}