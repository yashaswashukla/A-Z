/*
GFG:https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=get-minimum-element-from-stack
Leetcode: https://leetcode.com/problems/min-stack/
*/
#include <bits/stdc++.h>
using namespace std;
/*
-----------------------Using Extra Space------------------------
First Idea, is to use another stack which will help us
find the minimum element currently present in the stack

----------------------------Push--------------------------------

-->  While Pushing in the stack if the new element is
-->  smaller than the current top of the second stack
-->  we will insert that element in the second stack

---------------------------Pop----------------------------------
-->  When we are popping any element from the main stack and
-->  if that element matches with the current top of the
-->  second stack then we will pop from the second stack as well
-->  and we will update the minEle

----------------------------GetMinEle---------------------------
-->  Just return the minEle
*/

class stackWithSpace
{
    stack<int> s;
    stack<int> ss; // Supporting Stack;
    int minEle = -1;

public:
    int getMin()
    {
        return minEle;
    }
    int pop()
    {
        int x = -1;
        if (!s.empty())
        {
            x = s.top();
            s.pop();
            if (ss.top() == x)
            {
                ss.pop();
                minEle = (!ss.empty()) ? ss.top() : -1;
            }
            return x;
        }

        return x;
    }
    void push(int x)
    {
        s.push(x);
        if (ss.empty() || x <= minEle)
            ss.push(x), minEle = x;
    }
};

/*
-----------------------Using Extra Space------------------------
-->  Using Pair to store the element as the first value and the
-->  second Value will be the minimum element till now

*/
class pairStack
{
    stack<pair<int, int>> s;

public:
    int getMin()
    {
        if (!s.empty())
            return s.top().second;
        return -1;
    }
    int pop()
    {
        int x = -1;
        if (!s.empty())
        {
            x = s.top().first;
            s.pop();
        }

        return x;
    }
    void push(int x)
    {
        if (s.empty())
            s.push({x, x});
        else if (x > s.top().second)
            s.push({x, s.top().second});
        else
            s.push({x, x});
    }
};

/*
-----------------------Without Using Extra Space------------------------

Main intuition behind this approach is that if we insert a value which is min
and which can be determined somehow we will know when to update the value and
what to return

-----------------------------------Push-----------------------------------

-->  We will store the minimum value in an element minEle, First Value,
-->  is directly inserted in the stack and it is also stored in the minEle
-->  Now, If we face any value that is being inserted in the stack which is
-->  smaller than the minEle, we will update minEle to it and while pushing
-->  that element in the stack but we don't push the exact Value. We will insert
-->  a new value that will be calculated by the formula: push(2*val - min)

-----------------------------------Pop-----------------------------------

--> If the value at the top of the stack is lesser than the minEle, then we
--> the value being popped out is the minimum value, hence return the minEle.
--> But, inorder to get the previous minimum element we follow the formula we
--> used previously. Hence, val = 2*minEle - stack.top()

-----------------------------------getMin-----------------------------------

--> Just return the minEle

-----------------------------------getMin-----------------------------------

--> If the top element is smaller than the minEle, then return the minEle
*/

class noExtraSpace
{
    stack<int> s;
    int minEle = INT_MAX;

public:
    int getMin()
    {
        return minEle;
    }
    int pop()
    {
        int x = -1;
        if (!s.empty())
        {
            x = s.top();
            s.pop();

            if (x < minEle)
                minEle = 2 * minEle - x;
        }

        return x;
    }
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
        }
        else if (x < minEle)
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
    }
};