/*
GFG:https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here
        unordered_set<int> hash;
        for (int i = 0; i < N; i++)
            hash.insert(A[i]);
        vector<pair<int, int>> ans;

        for (int i = 0; i < M; i++)
        {
            if (hash.find(X - B[i]) != hash.end())
                ans.push_back({X - B[i], B[i]});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}