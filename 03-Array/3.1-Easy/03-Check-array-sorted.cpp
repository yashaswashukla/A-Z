/*
GFG:https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool arraySortedOrNot(int arr[], int n)
    {
        // code here
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }
};
int main()
{
}