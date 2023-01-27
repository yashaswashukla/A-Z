/*
GFG: https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-queue-using-array
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
#define e5 100005

int que[e5];
int front = 0;
int rear = 0;
void MyQueue ::push(int x)
{
    if (rear < e5)
        que[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    if (front >= rear)
        return -1;
    int x = que[front++];
    return x;
}
