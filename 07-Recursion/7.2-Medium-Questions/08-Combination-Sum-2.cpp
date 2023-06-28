/*
Gfg:https://practice.geeksforgeeks.org/problems/combination-sum-ii/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(vector<int> &arr, int idx, int sum)
    {
        if (!sum)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx and arr[i] == arr[i - 1])
                continue;
            if (sum < 0)
                return;
            temp.push_back(arr[i]);
            helper(arr, i + 1, sum - arr[i]);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return ans;
    }
};
int main()
{
}