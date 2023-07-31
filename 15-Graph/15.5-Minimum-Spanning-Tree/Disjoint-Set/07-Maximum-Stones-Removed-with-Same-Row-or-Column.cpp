/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1
Leetcode:https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }
    void join(vector<int> &parent, int row, int col)
    {
        int a = find(parent, row), b = find(parent, col);
        parent[b] = a;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        int n = maxRow + maxCol + 2;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_set<int> hash;
        for (auto it : stones)
        {
            int row = it[0], col = it[1] + maxRow + 1;
            join(parent, row, col);
            hash.insert(row);
            hash.insert(col);
        }
        int ans = stones.size();
        for (auto it : hash)
            if (find(parent, it) == it)
                ans--;
        return ans;
    }
};
int main()
{
}