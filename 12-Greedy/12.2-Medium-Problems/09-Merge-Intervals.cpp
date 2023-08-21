/*
Gfg:https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
Leetcode:https://leetcode.com/problems/merge-intervals/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            auto back = ans.back();
            if (back[1] < intervals[i][0])
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