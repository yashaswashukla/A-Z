/*
Gfg:https://practice.geeksforgeeks.org/problems/count-square-submatrices-with-all-ones/1
Leetcode:https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSquares(int N, int M, vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            dp[i][0] = matrix[i][0];
        for (int j = 0; j < M; j++)
            dp[0][j] = matrix[0][j];

        for (int row = 1; row < N; row++)
            for (int col = 1; col < M; col++)
                if (matrix[row][col] == 0)
                    dp[row][col] = 0;
                else
                    dp[row][col] = min(dp[row - 1][col], min(dp[row - 1][col - 1], dp[row][col - 1])) + 1;

        int ans = 0;
        for (int row = 0; row < N; row++)
            for (int col = 0; col < M; col++)
                ans += dp[row][col];
        return ans;
    }
};
int main()
{
}