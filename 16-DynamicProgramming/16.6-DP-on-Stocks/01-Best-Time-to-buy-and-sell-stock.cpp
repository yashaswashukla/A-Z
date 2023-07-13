/*
Leetcode:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
int main()
{
}