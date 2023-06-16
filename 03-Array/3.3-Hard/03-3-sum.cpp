/*
Link:https://leetcode.com/problems/3sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 or (i > 0 and nums[i] != nums[i - 1]))
            {

                int target = 0 - nums[i];
                int low = i + 1, high = n - 1;
                while (low < high)
                {
                    if (nums[low] + nums[high] == target)
                    {
                        ans.push_back({nums[i], nums[low], nums[high]});
                        while (low < high and nums[low] == nums[low + 1])
                            low++;
                        while (low < high and nums[high] == nums[high - 1])
                            high--;
                        low++, high--;
                    }
                    else if (nums[low] + nums[high] > target)
                        high--;
                    else
                        low++;
                }
            }
        }

        return ans;
    }
};
class gfgSolution
{
public:
    int closest3Sum(int A[], int N, int X)
    {
        int maxdiff = INT_MAX, ans = -1;
        sort(A, A + N);
        for (int i = 0; i < N - 2; i++)
        {
            if (i == 0 or (i > 0 and A[i] != A[i - 1]))
            {
                int low = i + 1, high = N - 1;
                while (low < high)
                {
                    int sum = A[i] + A[low] + A[high];
                    if (sum == X)
                        return X;
                    if (sum < X)
                        low++;
                    else if (sum > X)
                        high--;

                    if (abs(X - sum) < maxdiff)
                    {
                        maxdiff = abs(X - sum);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
}