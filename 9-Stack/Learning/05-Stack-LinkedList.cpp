/*
GFG: https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-stack-using-linked-list
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};
void MyStack ::push(int x)
{
    StackNode *temp = new StackNode(x);
    if (!temp)
        return;
    temp->next = top;
    top = temp;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (!top)
        return -1;

    int x = top->data;
    top = top->next;
    return x;
}
int main()
{
}