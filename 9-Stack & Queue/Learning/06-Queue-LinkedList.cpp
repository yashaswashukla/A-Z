/*
GFG:https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-queue-using-linked-list
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};
struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if (!front and !rear)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = rear->next;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    if (!front)
        return -1;
    int x = front->data;

    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    return x;
}
int main()
{
}