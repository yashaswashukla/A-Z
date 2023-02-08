/*
}
GFG:https://practice.geeksforgeeks.org/problems/asteroid-collision/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=asteroid-collision
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
/*
---> This question can be solved by using a stack. As for every negative value in array
---> we try to find a positive value before it, so they can collide.
---> Hence, the previous array can be stored in a stack.

---> If the element is positive we just push it into the stack
---> If the element is negative then we pop the stack till there is
---> a smaller positive value is present in the stack.
---> After the pop operation if the stack is empty then just push the
---> element in the array.
---> If the top element is negative then also push the element in the stack.

*/
class Solution
{
public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids)
    {
        stack<int> st;

        for (auto ast : asteroids)
        {
            if (ast > 0)
                st.push(ast);
            else
            {
                while (!st.empty() and st.top() > 0 and st.top() <= abs(ast))
                    st.pop();

                if (st.empty())
                    st.push(ast);
                else if (st.top() == abs(ast))
                    st.pop();
                else if (st.top() < 0)
                    st.push(ast);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}