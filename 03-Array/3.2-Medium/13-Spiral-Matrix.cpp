/*
GFG:https://practice.geeksforgeeks.org/problems/cd61add036272faa69c6814e34aa7007d5a25aa6/1
Leetcode:https://leetcode.com/problems/spiral-matrix/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (top <= bottom and left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                k--;
                if (!k)
                    return a[top][i];
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {

                k--;
                if (!k)
                    return a[i][right];
            }
            right--;

            if (top > bottom or left > right)
                break;

            for (int i = right; i >= left; i--)
            {
                k--;
                if (!k)
                    return a[bottom][i];
            }
            bottom--;

            for (int i = bottom; i >= top; i--)
            {
                k--;
                if (!k)
                    return a[i][left];
            }
            left++;
        }
        return -1;
    }
};
int main()
{
}