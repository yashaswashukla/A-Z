/*
Gfg:https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
Leetcode:https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
*/
#include <bits/stdc++.h>
using namespace std;
class tabSolution
{
public:
    int minDifference(int arr[], int n)
    {
        int sum = accumulate(arr, arr + n, 0);
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int idx = 0; idx < n; idx++)
            dp[idx][0] = 1;
        if (arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
            for (int target = 1; target <= sum; target++)
            {
                bool not_taken = dp[idx - 1][target], taken = false;
                if (arr[idx] <= target)
                    taken = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = not_taken or taken;
            }

        int ans = sum + 1;
        for (int target = 0; target <= sum; target++)
            if (dp[n - 1][target] and dp[n - 1][sum - target])
                ans = min(ans, abs(sum - target - target));
        return ans;
    }
};
class spaceOptimization
{
public:
    int minDifference(int arr[], int n)
    {
        int sum = accumulate(arr, arr + n, 0);
        vector<int> prev(sum + 1, 0);
        prev[0] = 1;
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int idx = 1; idx < n; idx++)
        {
            vector<int> row(sum + 1, 0);
            row[0] = 1;
            for (int target = 1; target <= sum; target++)
            {
                int not_taken = prev[target], taken = false;
                if (target >= arr[idx])
                    taken = prev[target - arr[idx]];
                row[target] = not_taken + taken;
            }
            prev = row;
        }
        int ans = sum + 1;
        for(int target = 0; target <= sum / 2 + 1; target++)
            if(prev[target] and prev[sum - target])
                ans = min(ans, abs(sum - 2 * target));
        return ans;
    }
};
int main()
{
}