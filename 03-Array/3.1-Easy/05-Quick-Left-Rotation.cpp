/*
GFG:https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Reversal Algorithm
    void leftRotate(int arr[], int k, int n)
    {
        k = k % n;
        reverse(arr, arr + k);
        reverse(arr + k, arr + n);
        reverse(arr, arr + n);
    }
    void rightRotation(int arr[], int k, int n)
    {
        k = k % n;
        reverse(arr + n - k, arr + n);
        reverse(arr, arr + n - k);
        reverse(arr, arr + n);
    }
};
int main()
{
}