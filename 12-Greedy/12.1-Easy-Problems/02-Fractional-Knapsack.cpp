/*
Gfg:https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
};
class Solution
{
public:
    static bool comp(struct Item &a, struct Item &b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 >= r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        sort(arr, arr + n, comp);
        double totalValue = 0;
        int idx = 0;
        while (W and idx < n)
        {
            if (arr[idx].weight < W)
            {
                W -= arr[idx].weight;
                totalValue += arr[idx].value;
            }
            else
            {
                totalValue += ((double)arr[idx].value / (double)arr[idx].weight) * W;
                W = 0;
            }
            idx++;
        }
        return totalValue;
    }
};
int main()
{
}