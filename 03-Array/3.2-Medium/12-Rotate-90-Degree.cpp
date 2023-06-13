/*
GFG:https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // Using Observation, we can see that the first column is the reverse of the first row

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
                if (n - 1 - i == n / 2)
                    break;
            }
    }
};
int main()
{
}