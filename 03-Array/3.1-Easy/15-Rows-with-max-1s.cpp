/*
GFG:https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int j = m - 1, answer = 0;

        for (int i = 0; i < n; i++)
        {
            // Flag to check if the previous row has more or less number of 1s
            bool previousRowWithLess1s = false;

            // Finding the left most 1 in the row
            while (j >= 0 && arr[i][j] == 1)
            {
                j = j - 1;
                previousRowWithLess1s = true;
            }

            // If there is 1 left of previous j
            // Then we update the answer
            if (previousRowWithLess1s)
                answer = i;
        }

        // Edge case if there is no 1

        if (answer == 0 && arr[0][m - 1] == 0)
            return -1;

        return answer;
    }
};
int main()
{
}