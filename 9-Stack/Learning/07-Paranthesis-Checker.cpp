/*
GFG:https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=parenthesis-checker
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;

        for (char ch : x)
        {
            if (ch == '(' or ch == '{' or ch == '[')
                st.push(ch);
            else
            {
                if (st.empty())
                    return false;
                if (st.top() == '(' and ch == ')')
                    st.pop();
                else if (st.top() == '{' and ch == '}')
                    st.pop();
                else if (st.top() == '[' and ch == ']')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
int main()
{
}