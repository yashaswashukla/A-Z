/*
GFG:
Leetcode: https://leetcode.com/problems/next-greater-element-ii/
*/
#include <bits/stdc++.h>
using namespace std;
/*
---> Same intuition as the last question in this we will make the array circular
---> by taking a mod with size of the array and run the loop 2*size-1
 */
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top() <= nums[i % n])
                st.pop();

            if (i < n)
                if (!st.empty())
                    ans[i] = st.top();
            st.push(nums[i % n]);
        }
        return ans;
    }
};
int main()
{
}