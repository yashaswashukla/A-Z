/*
Gfg:https://practice.geeksforgeeks.org/problems/combination-sum-iii/1
Leetcode:https://leetcode.com/problems/combination-sum-iii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void helper(vector<int> &base, int idx, int k, int sum)
    {
        if (temp.size() > k)
            return;
        if (!sum and temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < base.size(); i++)
        {
            if (sum < 0)
                return;
            temp.push_back(base[i]);
            helper(base, i + 1, k, sum - base[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int K, int N)
    {
        // code here
        vector<int> base;
        for (int i = 1; i <= 9; i++)
            base.push_back(i);

        helper(base, 0, K, N);
        return ans;
    }
};
int main()
{
}