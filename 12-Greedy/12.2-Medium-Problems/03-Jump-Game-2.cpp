/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
Leetcode:https://leetcode.com/problems/jump-game-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int i = 0, lastJumped = 0, maxReachable = 0, jumps = 0;
        while (i < n and lastJumped < n - 1)
        {
            maxReachable = max(maxReachable, i + arr[i]);
            if (lastJumped == i)
            {
                lastJumped = maxReachable;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};
int main()
{
}