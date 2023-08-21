/*
Gfg:https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    static bool comparator(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;

        for (int i = 1; i < n; i++)
            maxi = max(maxi, arr[i].dead);

        vector<int> vis(maxi, 0);
        int count = 0, maxProfit = 0;
        for (int i = 0; i < n; i++)
            for (int j = arr[i].dead - 1; j >= 0; j--)
                if (!vis[j])
                {
                    vis[j] = 1;
                    count++;
                    maxProfit += arr[i].profit;
                    break;
                }

        return {count, maxProfit};
    } 
};
int main()
{
}