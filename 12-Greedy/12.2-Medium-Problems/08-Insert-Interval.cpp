/*
Gfg:https://practice.geeksforgeeks.org/problems/insert-interval-1666733333/1?page=1&sortBy=accuracy
Leetcode:https://leetcode.com/problems/insert-interval/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        if (!n)
            return {newInterval};

        int idx = -1;
        for (int i = 0; i < n; i++)
            if (intervals[i][0] < newInterval[0])
                idx = i;
        intervals.insert(intervals.begin() + idx + 1, newInterval);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i <= n; i++)
        {
            vector<int> back = ans.back();
            if (intervals[i][0] > back[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(back[1], intervals[i][1]);
        }
        return ans;
    }
};
int main()
{
}