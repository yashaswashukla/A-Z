/*
GFG:https://practice.geeksforgeeks.org/problems/missing-number4257/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int missingNumber(int A[], int N)
    {
        // Your code goes here
        int total = (N * (N + 1)) / 2;

        for (int i = 0; i < N - 1; i++)
            total -= A[i];
        return total;
    }
};
int main()
{
}