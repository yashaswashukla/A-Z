/*
Gfg:https://practice.geeksforgeeks.org/problems/count-subarray-with-k-odds/1
Leetcode:https://leetcode.com/problems/count-number-of-nice-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int left = 0, right = 0, odds = 0, count = 0;
        for (; right < nums.size(); right++)
        {
            if (nums[right] % 2)
                odds++;
            while (odds > k)
            {
                if (nums[left] % 2)
                    odds--;
                left++;
            }
            if (odds == k)
            {
                int i = left;
                while (i < right)
                    if (nums[i] % 2 == 0)
                        i++;
                    else
                        break;
                count += i - left + 1;
            }
        }
        return count;
    }
};
int main()
{
}