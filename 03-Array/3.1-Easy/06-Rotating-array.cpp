/*
GFG:https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void leftRotate(int arr[], int n, int k)
    {
        // code here
        k = k % n;
        reverse(arr, arr + k);
        reverse(arr + k, arr + n);
        reverse(arr, arr + n);
    }
};
int main()
{
    
}