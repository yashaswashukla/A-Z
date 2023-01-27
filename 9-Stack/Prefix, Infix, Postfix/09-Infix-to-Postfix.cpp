/*
GFG: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix
Leetcode:
*/

/*
--> Traverse the expression from left to right
--> But, If '(' is encountered then add it to the stack with out checking anything
--> If ')' is encountered then pop all the elements till '(' is found and add everything
--> except the parenthesis to the the ans string
--> If any operand is encountered, pop all the operand which have greater precedence or
--> same precedence add it to the string ans and remove it, then add that operand to the
--> stack

--> Remove all the elements from the stack and add it to string ans

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    string infixToPostfix(string s)
    {
        string ans = "";
        stack<char> st;
        unordered_map<char, int> pred;

        pred['^'] = 3, pred['*'] = 2, pred['/'] = 2, pred['+'] = 1, pred['-'] = 1, pred['('] = -1;

        for (auto ch : s)
        {
            if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or (ch >= '0' and ch <= '9'))
                ans += ch;

            else if (ch == '(')
                st.push(ch);
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() and pred[ch] <= pred[st.top()])
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
int main()
{
}