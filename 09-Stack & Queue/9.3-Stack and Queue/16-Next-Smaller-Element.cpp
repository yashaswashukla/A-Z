/*
GFG: https://practice.geeksforgeeks.org/problems/immediate-smaller-element1142/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=immediate-smaller-element
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void immediateSmaller(vector<int> &arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                arr[i] = arr[i + 1];
            else
                arr[i] = -1;
        }

        arr[n - 1] = -1;
    }
};
int main()
{
}