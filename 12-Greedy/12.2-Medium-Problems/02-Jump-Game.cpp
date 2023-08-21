/*
Gfg:https://practice.geeksforgeeks.org/problems/jump-game/1
Leetcode:https://leetcode.com/problems/jump-game/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), maxReachable = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxReachable)
                return false;
            maxReachable = max(maxReachable, i + nums[i]);
        }
        return true;
    }
};
int main()
{
}