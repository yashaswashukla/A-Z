/*
GFG:https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        // We just have to iterate from right and keep track of the largest number so far
        // If the current number is greater than the largest, update the largest and push it in the array

        int leader = a[n - 1];
        vector<int> ans;
        // Right most element is always a leader
        ans.push_back(leader);

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] >= leader)
            {
                // Comparing from the current leader, if greater then update the leader and pushback the leader.
                leader = a[i];
                ans.push_back(leader);
            }
        }

        // As we pushback the leaders in the array from back, we have to reverse to get the correct order.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}