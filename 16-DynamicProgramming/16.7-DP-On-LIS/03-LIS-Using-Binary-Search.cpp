/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lower_bound(vector<int> &temp, int key)
    {
        int low = 0, high = temp.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (temp[mid] >= key)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
    int longestSubsequence(int n, int arr[])
    {
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
                temp.push_back(arr[i]);
            else
            {
                int ind = lower_bound(temp, arr[i]);
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};
int main()
{
}