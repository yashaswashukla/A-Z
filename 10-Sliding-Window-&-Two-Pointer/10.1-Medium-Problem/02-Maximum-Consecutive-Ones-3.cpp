/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1
Leetcode:https://leetcode.com/problems/max-consecutive-ones-iii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, right = 0, zero = 0, ans = 0;
        while (right < nums.size())
        {
            if (!nums[right])
                zero++;
            while (zero > k)
            {
                if (!nums[left])
                    zero--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
int main()
{
}