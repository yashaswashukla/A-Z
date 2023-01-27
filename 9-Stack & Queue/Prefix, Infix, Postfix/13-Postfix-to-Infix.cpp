/*
}
GFG: https://practice.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

/*
-->> Postfix notation during conversion will always be processed
-->> from left to right and vice-versa

---> To convert from Postfix to infix,
---> First the Postfix is traversed from right to left
---> If we find any operand then we insert it in to the stack
---> If we find any operator then we pop 2 elements from the stack
---> make a string of '(' + op2 + operator + op1 + ')'
---> Insert it in the stack and repeat the process till the prefix
---> string is completely traversed

---> And at last we return the top element of the stack

*/
class Solution
{
public:
    string postToInfix(string exp)
    {
        string ans = "";
        stack<string> st;
        for (char ch : exp)
        {
            if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))
                st.push(string(1, ch));
            // Using string class fill constructor
            // to_string is used to convert integers to strings
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push("(" + op2 + ch + op1 + ")");
            }
        }

        return st.top();
    }
};
int main()
{
}