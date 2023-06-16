/*
Link:https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i == 0 or (i > 0 and arr[i] != arr[i - 1]))
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (j - 1 == i or arr[j] != arr[j - 1])
                    {
                        int low = j + 1, high = n - 1;
                        while (low < high)
                        {
                            int sum = arr[i] + arr[j] + arr[low] + arr[high];
                            if (sum == k)
                            {
                                ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                                while (low < high and arr[low] == arr[low + 1])
                                    low++;
                                while (low < high and arr[high] == arr[high - 1])
                                    high--;
                                low++, high--;
                            }
                            else if (sum < k)
                                low++;
                            else
                                high--;
                        }
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