/*
GFG:https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int majorityElement(int a[], int size)
    {
        int vote = 1, idx = 0;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == a[idx])
                vote++;
            else
                vote--;
            if (vote <= 0)
            {
                vote = 1;
                idx = i;
            }
        }
        vote = 0;
        for (int i = 0; i < size; i++)
            if (a[i] == a[idx])
                vote++;
        return vote > size / 2 ? a[idx] : -1;
    }
};
int main()
{
}