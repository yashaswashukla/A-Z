/*
Gfg:https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
Leetcode:https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
public:
    vector<int> kthLargest(int k, int arr[], int n)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else if (arr[i] > pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }

            ans.push_back(pq.size() == k ? pq.top() : -1);
        }
        return ans;
    }
};
class leetSolution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto x : nums)
        {
            pq.push(x);
            while (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
int main()
{
}