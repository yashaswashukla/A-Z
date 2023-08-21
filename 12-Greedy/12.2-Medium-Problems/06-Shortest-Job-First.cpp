/*
Gfg:https://practice.geeksforgeeks.org/problems/shortest-job-first/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long timeElapsed = 0, waitingTime = 0;

        for (int i = 0; i < n; i++)
        {
            waitingTime += timeElapsed - 0;
            timeElapsed += bt[i];
        }
        return waitingTime / n;
    }
};
int main()
{
}