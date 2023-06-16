/*
Gfg:https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
Leetcode:https://leetcode.com/problems/merge-intervals/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            auto prev = ans.back();

            if (prev[1] >= intervals[i][0])
                ans.back()[1] = max(prev[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
int main()
{
}