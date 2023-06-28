/*
Gfg:https://practice.geeksforgeeks.org/problems/subset-sum-ii/1
Leetcode:https://leetcode.com/problems/subsets-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(vector<int> &nums, int idx)
    {
        ans.push_back(temp);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx and nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            helper(nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> printUniqueSubsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }
};
int main()
{
}