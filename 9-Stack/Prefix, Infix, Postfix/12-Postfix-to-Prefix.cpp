/*
GFG: https://practice.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

/*
-->> Prefix notation during conversion will always be processed
-->> from left to right and vice-versa

---> Process the string from right to left
---> If operand is encountered then push it in the stack
---> If operator is encountered then pop 2 elements from the stack
---> Make a string operator + op2 + op1, push it in the stack
---> Repeat the following steps till the end of the string

---> Return the top element of the stack

 */

class Solution
{
    string postToPre(string post_exp)
    {
        string temp = "";
        stack<string> st;

        for (char ch : post_exp)
        {
            if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))
                st.push(string(1, ch));
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();

                temp = ch + op2 + op1;
                st.push(temp);
            }
        }

        return st.top();
    }
};
int main()
{
}