/*
Gfg:https://practice.geeksforgeeks.org/problems/subset-sums2234/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> &arr, int idx, int sum, vector<int> &ans)
    {
        ans.push_back(sum);

        for (int i = idx; i < arr.size(); i++)
        {
            sum += arr[i];
            helper(arr, i + 1, sum, ans);
            sum -= arr[i];
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(arr, 0, 0, ans);
        return ans;
    }
};
int main()
{
}