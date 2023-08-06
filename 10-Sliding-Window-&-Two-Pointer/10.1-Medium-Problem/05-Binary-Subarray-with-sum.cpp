/*
Gfg:https://practice.geeksforgeeks.org/problems/binary-subarray-with-sum/0
Leetcode:https://leetcode.com/problems/binary-subarrays-with-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lessthanequalto(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int left = 0, right = 0, sum = 0, count = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (left <= right and sum > goal)
                sum -= nums[left++];

            count += (right - left + 1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return lessthanequalto(nums, goal) - lessthanequalto(nums, goal - 1);
    }
};
int main()
{
}