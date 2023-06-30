/*
Gfg:https://practice.geeksforgeeks.org/problems/word-search/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    bool dfs(int i, int j, string &word, int idx, vector<vector<char>> &board, vector<vector<int>> &vis)
    {
        if (idx >= (int)word.length())
            return true;
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k], ncol = j + col[k];

            if (nrow >= 0 and ncol >= 0 and nrow < board.size() and ncol < board[0].size())
            {
                if (!vis[nrow][ncol] and board[nrow][ncol] == word[idx])
                    if (dfs(nrow, ncol, word, idx + 1, board, vis))
                        return true;
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    if (dfs(i, j, word, 1, board, vis))
                        return true;
        return false;
    }
};
int main()
{
}