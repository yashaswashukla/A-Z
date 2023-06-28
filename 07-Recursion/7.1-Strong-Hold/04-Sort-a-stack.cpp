/*
Gfg:https://practice.geeksforgeeks.org/problems/sort-a-stack/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void SortedStack ::sort()
    {
        if (s.size() == 1)
            return;
        int t = s.top();
        s.pop();

        sort();

        if (s.top() > t)
        {
            int x = s.top();
            s.pop();
            s.push(t);
            s.push(x);
            sort();
        }
        else
            s.push(t);
        return;
    }
};
int main()
{
}