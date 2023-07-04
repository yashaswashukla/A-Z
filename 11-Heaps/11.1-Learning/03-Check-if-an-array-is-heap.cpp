/*
Gfg:https://practice.geeksforgeeks.org/problems/does-array-represent-heap4345/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMaxHeap(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int leftchild = i * 2 + 1, rightchild = i * 2 + 2;
            if ((leftchild < n and a[i] <= a[leftchild]) or (rightchild < n and a[i] <= a[rightchild]))
                return false;
        }
        return true;
    }
};
int main()
{
}