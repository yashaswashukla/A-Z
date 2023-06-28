/*
Gfg:https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void insert(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int tp = st.top();
        st.pop();
        insert(st, x);
        st.push(tp);
    }
    void Reverse(stack<int> &st)
    {
        if (st.size() == 1)
            return;

        int sec = st.top();
        st.pop();
        Reverse(st);
        insert(st, sec);
    }
};

int main()
{
}