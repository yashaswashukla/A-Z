/*
}
GFG: https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string preToInfix(string pre_exp)
    {
        string ans = "";
        stack<string> st;
        for (int i = pre_exp.length() - 1; i >= 0; i--)
        {
            char ch = pre_exp[i];
            if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))
                st.push(string(1, pre_exp[i]));
            else if (st.size() >= 2)
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                ans = "(" + op1 + ch + op2 + ")";
                // cout << ans << endl;
                st.push(ans);
            }
        }

        return st.top();
    }
};
int main()
{
}