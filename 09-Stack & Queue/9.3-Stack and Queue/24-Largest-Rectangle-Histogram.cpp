/*
GFG: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-rectangular-area-in-a-histogram
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
/*
---> To solve this problem we need to find the largest rectangle
---> which can be formed by current bar. To do that we will have to
---> find the smallest to the right and to the left. Difference
---> of both the indicies will be the width and height is current elevation.
*/
// TC: O(n^2) and SC: O(1)
class naiveSolution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i, right = i;
            int j = i - 1;
            while (j >= 0 and arr[j] >= arr[i])
            {
                left = j;
                j--;
            }
            j = i + 1;
            while (j < n and arr[j] >= arr[i])
            {
                right = j;
                j++;
            }

            maxArea = max(maxArea, arr[i] * (right - left + 1));
        }
        return maxArea;
    }
};
/*
---> To store the left smallest and right smallest we use stacks to do it.
---> Traverse the array twice and find the next smallest element on both the sides.
*/
class betterSolution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        vector<long long> left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;

            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;
            st.push(i);
        }
        long long maxArea = 0;
        for (int i = 0; i < n; i++)
            maxArea = max(maxArea, arr[i] * (right[i] - left[i] + 1));

        return maxArea;
    }
};
int main()
{
}