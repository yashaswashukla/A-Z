/*
GFG: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stock-span-problem
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
// TC: O(n^2) and SC: O(1)
class naiveSolution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            int count = 0;
            int j = i - 1;
            while (j >= 0 and price[j] <= price[i])
            {
                count++;
                j--;
            }
            ans[i] += count;
        }
        return ans;
    }
};
/*
----> In this question we have to find out the number of days before current day the
----> price of stock was "consecutively" lower.
----> In other words we simply have to find out the index of previous greatest element
*/
// TC: O(n) and SC: O(n)
class betterSolution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and st.top().first <= price[i])
                st.pop();
            if (st.empty())
                ans.push_back(i + 1);
            else
                ans.push_back(abs(st.top().second - i));
            st.push({price[i], i});
        }

        return ans;
    }
};
int main()
{
}