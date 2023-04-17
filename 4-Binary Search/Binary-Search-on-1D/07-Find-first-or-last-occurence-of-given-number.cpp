/*
GFG:https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int find_first(int arr[], int n, int x)
    {
        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = right + (left - right) / 2;

            if (arr[mid] == x)
            {
                ans = mid;
                right = mid - 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
    int find_last(int arr[], int n, int x)
    {
        int left = 0, right = n - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = right + (left - right) / 2;

            if (arr[mid] == x)
            {
                ans = mid;
                left = mid + 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }

public:
    vector<int> find(int arr[], int n, int x)
    {
        vector<int> ans;

        ans.push_back(find_first(arr, n, x));
        ans.push_back(find_last(arr, n, x));

        return ans;
    }
};
int main()
{
}