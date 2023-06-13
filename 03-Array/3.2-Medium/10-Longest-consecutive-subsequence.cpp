/*
GFG:https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/0?problemType=functional&page=1&query=problemTypefunctionalpage1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        // Creating a hash to store all the values of the array
        unordered_set<int> hash;

        for (int i = 0; i < N; i++)
            hash.insert(arr[i]);

        // Now we try and find out the longest subsequence.
        // We find out whether the current element is the starting of any subsequence or not
        // We do that by finding out if element - 1 is present or not, if it is present, then not the starting

        int ans = 1;
        for (int i = 0; i < N; i++)
        {
            // If element - 1 is present then we ignore it and move forward
            if (hash.count(arr[i] - 1))
                continue;
            int count = 1;
            int x = arr[i] + 1;
            while (hash.count(x))
                x++, count++;
            ans = max(ans, count);
        }
        return ans;
    }
};
int main()
{
}