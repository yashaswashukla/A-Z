/*
Gfg:https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
Leetcode:https://leetcode.com/problems/fruit-into-baskets/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        int type1 = 0, type2 = 0, curr = 0, count_2 = 0, ans = 0;
        for (auto x : fruits)
        {
            if (x == type1 or x == type2)
                curr++;
            else
                curr = count_2 + 1;

            if (x == type2)
                count_2++;
            else
                count_2 = 1;

            if (x != type2)
                type1 = type2, type2 = x;
            ans = max(ans, curr);
        }
        return ans;
    }
};
int main()
{
}