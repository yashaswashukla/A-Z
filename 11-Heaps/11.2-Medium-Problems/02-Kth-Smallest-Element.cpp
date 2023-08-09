/*
Gfg:https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i <= r; i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
int main()
{
}