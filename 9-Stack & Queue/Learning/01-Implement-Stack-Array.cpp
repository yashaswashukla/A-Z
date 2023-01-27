/*
GFG: https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-stack-using-array
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;

int st[1000];
int top = -1;
// Function to push an integer into the stack.
void MyStack ::push(int x)
{
    if (top < 1000)
        st[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top < 0)
        return -1;
    return st[top--];
}
