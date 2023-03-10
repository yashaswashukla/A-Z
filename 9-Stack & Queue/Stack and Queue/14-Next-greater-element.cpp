/*
GFG: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=next-larger-element
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
/*

---> TC: O(n^2) and SC: O(n)

---> We will simply iterate to the right of the current element
---> to find the just greater element to the right if found we break
---> the loop, hence stopping us to go any further in the array
*/
class naiveSolution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans(n, -1);

        for (int i = 0; i < n - 1; i++)
        {
            int nge = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > nge)
                {
                    nge = arr[j];
                    break;
                }
            }

            if (nge != arr[i])
                ans[i] = nge;
        }

        return ans;
    }
};

/*
---> Trying to reduce the complexity to O(n), It means removing the inner loop
---> Can we use any data structure to hold values for us and give it back to us.
---> Yes, We can use stack to do this task for us.

--->> Any question in which we have a loop like (j = i+1 to n) it's complexity can be
--->> reduced by using a Stack
`````
---> To solve this question:
1 3 2 4
Right array of 1 is : 3 2 4, next greater element is 3

Right array of 3 is: 2 4, next greater element is 4

Right array of 2 is: 4, and greater element is also 4

Right array of 4 is: {}, hence -1;

---> If we observe we can hold the entire right array in a data structure and find
---> the next greater element as we want.

Algorithm:

---> If the stack is empty just print -1 and push that element in the stack
---> If the stack top is greater than that element just print the stack top
---> Also push the current element in the stack
---> If the current element is greater than stack top then pop till you get
---> the element greater than current as the stack top and print that element
---> Also push that element in the stack


 */
class optimalSolution
{
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> st;
        vector<long long> ans;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(-1);
            else
            {
                if (st.top() > arr[i])
                    ans.push_back(st.top());
                else
                {
                    while (!st.empty() and st.top() <= arr[i])
                        st.pop();
                    if (st.empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        // Important as we traverse from left to right solution vector will be in the reverse order
        return ans;
    }
};
int main()
{
}