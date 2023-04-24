/*
GFG: https://practice.geeksforgeeks.org/problems/sum-of-subarray-minimum/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sum-of-subarray-minimum
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
/*
---> Generating all the possible sub arrays and finding the min in those arrays
---> and adding that min element to the sum

----> TC: O(n^3) and SC: O(1)
*/
class naiveSolution
{
public:
    int sumSubarrayMins(int N, vector<int> &arr)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                int min = arr[i];
                for (int k = i; k <= j; k++)
                    if (arr[k] < min)
                        min = arr[k];

                sum += min;
            }
        }
        return sum;
    }
};
/*
---> Main idea to solve this question is to find the next and previous smaller numbers index
---> which will help us find out the number of subarrays will have this element as the smallest
---> Now, after finding the indices of next and previous smaller number, we will get their
---> distance from the current element and multiply those values, that will give us the number
---> of subarrays that will have the current element as the min value

EX:              [2, 9, 7, 8, 3, 4, 6, 1]
                 |            |        |
        the previous less   curr      the next less
           element of 3     idx = 4   element of 3
            index = 0                 index = 7

        Distance from previous less = abs(4-0) = 4
        Distance from next less = abs(4-7) = 3

        Hence, Number of subarrays with this number as the min = 4*3 = 12
        So, contribution of 3 will be 3*12 = 36
*/
class betterSolution
{
public:
    int sumSubarrayMins(int n, vector<int> &arr)
    {
        int mod = 1e9 + 7;
        stack<int> st;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + (arr[i] * left[i] * right[i]) % mod) % mod;
        return ans % mod;
    }
};
class optimalSolution
{
public:
    int sumSubarrayMins(int n, vector<int> &arr)
    {
        int mod = 1e9 + 7;
        int ans = 0;
        stack<int> st;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() and (i == n or arr[st.top()] > arr[i]))
            {
                int cur = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                ans += ((cur - left) * (right - cur) * arr[i]) % mod;
            }
            st.push(i);
        }

        return ans;
    }
};
int main()
{
}