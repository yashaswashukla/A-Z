/*
GFG: https://practice.geeksforgeeks.org/problems/remove-k-digits/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-k-digits
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
// Remove the first peak element.
class naiveSolution
{
public:
    string removeKdigits(string s, int k)
    {
        while (k > 0)
        {
            int n = s.size();
            int i = 0;
            while (i + 1 < n && s[i] <= s[i + 1])
                i++;
            s.erase(i, 1);
            k--;
        }
        int i = 0;
        while (i < (int)s.size() - 1 && s[i] == '0')
            i++;
        s = s.substr(i, s.length() - i);

        return s == ""
                   ? "0"
                   : s;
    }
};
class optimalSolution
{
public:
    string removeKdigits(string s, int k)
    {
        stack<char> st;
        int n = (int)s.length();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and k and st.top() > s[i])
            {
                k--;
                st.pop();
            }
            if (!st.empty() or s[i] != '0')
                st.push(s[i]);
        }

        string ans;
        while (!st.empty())
        {
            if (k)
                k--;
            else
                ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};
int main()
{
}