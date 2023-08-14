/*
Gfg:https://practice.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1
Leetcode:https://leetcode.com/problems/rank-transform-of-an-array/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr, int n)
    {
        unordered_map<int, int> hash;
        set<int> pq;

        for (int i = 0; i < n; i++)
            pq.insert(arr[i]);

        int rank = 1;
        for (auto val : pq)
            hash[val] = rank++;
        

        for (auto &ele : arr)
            ele = hash[ele];
        return arr;
    }
};
int main()
{
}