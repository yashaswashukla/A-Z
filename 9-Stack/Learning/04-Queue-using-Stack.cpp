/*
GFG:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        input.push(x);
    }

    int dequeue()
    {
        if (input.empty())
            return -1;

        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        int x = output.top();
        output.pop();

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }

        return x;
    }
};
int main()
{
}