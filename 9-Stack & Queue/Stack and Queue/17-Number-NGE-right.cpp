/*
GFG: https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> ans;
        for (auto idx : indices)
        {
            int x = arr[idx];
            int count = 0;
            for (int i = idx + 1; i < n; i++)
            {
                if (arr[i] > x)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
int main()
{
}