/*
Gfg:https://practice.geeksforgeeks.org/problems/non-overlapping-intervals/1
Leetcode:https://leetcode.com/problems/non-overlapping-intervals/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int last = intervals[0][1], count = 0;
        for (int i = 1; i < n; i++)
        {
            if (last <= intervals[i][0])
                last = intervals[i][1];
            else
                count++;
        }
        return count;
    }
};
int main()
{
}