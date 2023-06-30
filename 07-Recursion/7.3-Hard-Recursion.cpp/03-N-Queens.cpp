/*
Gfg:https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
Leetcode:https://leetcode.com/problems/n-queens/
*/
#include <bits/stdc++.h>
using namespace std;
class leetSolution
{
public:
    bool safe(int row, int col, vector<string> &board, int n)
    {
        int duprow = row, dupcol = col;

        // Upper Diagornal
        while (duprow >= 0 and dupcol >= 0)
            if (board[duprow--][dupcol--] == 'Q')
                return false;

        // Left Side
        duprow = row, dupcol = col;

        while (dupcol >= 0)
            if (board[duprow][dupcol--] == 'Q')
                return false;

        // Lower Diagonal
        duprow = row, dupcol = col;
        while (dupcol >= 0 and duprow < n)
            if (board[duprow++][dupcol--] == 'Q')
                return false;

        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (safe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string temp(n, '.');
        vector<string> board(n, temp);

        solve(0, ans, board, n);
        return ans;
    }
};
class geekSolution
{
public:
    bool safe(int row, int col, vector<vector<bool>> &board, int n)
    {
        int duprow = row, dupcol = col;

        // Upper Diagonal;

        while (duprow >= 0 and dupcol >= 0)
            if (board[duprow--][dupcol--])
                return false;

        // Left side
        duprow = row, dupcol = col;

        while (dupcol >= 0)
            if (board[duprow][dupcol--])
                return false;

        // Lower diagonal
        duprow = row, dupcol = col;

        while (duprow < n and dupcol >= 0)
            if (board[duprow++][dupcol--])
                return false;

        return true;
    }
    void solve(int col, vector<vector<int>> &ans, vector<vector<bool>> &board, vector<int> &temp, int n)
    {
        if (col == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (safe(row, col, board, n))
            {
                board[row][col] = 1;
                temp[col] = row + 1;
                solve(col + 1, ans, board, temp, n);
                temp[col] = 0;
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<int> temp(n);
        solve(0, ans, board, temp, n);
        return ans;
    }
};
int main()
{
}