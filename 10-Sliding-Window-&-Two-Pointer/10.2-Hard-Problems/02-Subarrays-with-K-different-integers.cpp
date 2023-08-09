/*
Gfg:https://practice.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1
Leetcode:https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(vector<int> &nums, int k)
    {
        int left = 0, right = 0, ans = 0;
        unordered_map<int, int> hash;
        while (right < nums.size())
        {
            hash[nums[right]]++;
            while (hash.size() > k)
            {
                hash[nums[left]]--;
                if (hash[nums[left]] == 0)
                    hash.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
class geekSolution
{
public:
    // Solution using vector instead of unordered_map
    int helper(vector<int> &nums, int n, int k)
    {
        int left = 0, right = 0, ans = 0, count = 0;
        vector<int> hash(n + 1, 0);

        while (right < n)
        {
            if (!hash[nums[right]])
                count++;
            hash[nums[right]]++;

            while (count > k)
            {
                hash[nums[left]]--;
                if (!hash[nums[left]])
                    count--;
                left++;
            }

            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int k)
    {
        return helper(arr, N, k) - helper(arr, N, k - 1);
    }
};
int main()
{
}