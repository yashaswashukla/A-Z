/*
GFG:https://practice.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-postfix-conversion
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

/*
-->> Prefix notation during conversion will always be processed
-->> from left to right and vice-versa


---> Traverse the pre_exp from left to right
---> If operand is encountered then push it in the stack
---> If operator is encountered then pop 2 elements from the stack
---> Make a string op1 + op2 + operator, push it in the stack
---> Repeat the following steps till the end of the string

---> Return the top element of the stack
*/
class Solution
{
public:
    string preToPost(string pre_exp)
    {
        string temp = "";
        stack<string> st;

        for (int i = pre_exp.length() - 1; i >= 0; i--)
        {
            char ch = pre_exp[i];

            if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))
                st.push(string(1, ch));
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();

                temp = op1 + op2 + ch;
                st.push(temp);
            }
        }

        return st.top();
    }
};
int main()
{
}