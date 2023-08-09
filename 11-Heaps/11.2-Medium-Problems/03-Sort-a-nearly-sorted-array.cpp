/*
Gfg:https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nearlySorted(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
            if (pq.size() == k + 1)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
int main()
{
}