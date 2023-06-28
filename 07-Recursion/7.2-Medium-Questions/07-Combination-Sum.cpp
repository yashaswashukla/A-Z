/*
Gfg:https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
Leetcode:https://leetcode.com/problems/combination-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class leetSolution
{
public:
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
            if (sum < 0)
                return;
            temp.push_back(arr[i]);
            helper(arr, i, sum - arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        helper(candidates, 0, target);
        return ans;
    }
};
class geekSolution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(vector<int> &A, int idx, int sum)
    {
        if (!sum)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < A.size(); i++)
        {
            if (i > idx and A[i] == A[i - 1])
                continue;
            if (sum < 0)
                return;
            temp.push_back(A[i]);
            helper(A, i, sum - A[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        sort(A.begin(), A.end());
        helper(A, 0, B);
        return ans;
    }
};
int main()
{
}