/*
Gfg:https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        int idx = coins.size() - 1;
        while (idx >= 0 and N)
        {
            if (N >= coins[idx])
            {
                N -= coins[idx];
                ans.push_back({coins[idx]});
            }
            else
                idx--;
        }
        return ans;
    }
};
int main()
{
}