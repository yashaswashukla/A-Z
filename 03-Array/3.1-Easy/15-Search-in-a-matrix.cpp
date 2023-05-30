/*
GFG:https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int matSearch(vector<vector<int>> &mat, int N, int M, int X)
    {
        // your code here
        int low = 0, high = M - 1;
        while (low < N and high >= 0)
        {
            if (mat[low][high] == X)
                return 1;
            else if (mat[low][high] < X)
                low++;
            else
                high--;
        }
        return 0;
    }
};
int main()
{
}