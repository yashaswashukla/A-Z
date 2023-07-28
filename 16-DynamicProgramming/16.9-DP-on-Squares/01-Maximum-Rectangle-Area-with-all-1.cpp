/*
Gfg:https://practice.geeksforgeeks.org/problems/max-rectangle/1
Leetcode:https://leetcode.com/problems/maximal-rectangle/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getArea(vector<int> &height)
    {
        int n = height.size();
        stack<int> st;
        vector<int> left(n, 0), right(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and height[st.top()] >= height[i])
                st.pop();

            if (st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;

            st.push(i);
        }
        while (st.size())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and height[st.top()] >= height[i])
                st.pop();
            if (st.empty())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, (right[i] - left[i] + 1) * height[i]);
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        vector<int> height(m, 0);
        int ans = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (M[row][col])
                    height[col] += 1;
                else
                    height[col] = 0;
            }
            ans = max(ans, getArea(height));
        }
        return ans;
    }
};
int main()
{
}