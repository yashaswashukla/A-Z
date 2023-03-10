/*
GFG: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stack-using-two-queues
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

void QueueStack ::push(int x)
{
    q1.push(x);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.empty())
        return -1;

    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int x = q1.front();
    q1.pop();

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    return x;
}
int main()
{
}