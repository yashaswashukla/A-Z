/*
Gfg:https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *segregate(Node *head)
    {
        if (!head or !head->next)
            return head;
        Node *zerohead = new Node(-1), *zero = zerohead;
        Node *onehead = new Node(-1), *one = onehead;
        Node *twohead = new Node(-1), *two = twohead;

        while (head)
        {
            if (head->data == 0)
            {
                zero->next = head;
                zero = head;
            }
            else if (head->data == 1)
            {
                one->next = head;
                one = head;
            }
            else
            {
                two->next = head;
                two = head;
            }
            head = head->next;
        }
        if (onehead->next)
        {
            one->next = twohead->next;
            zero->next = onehead->next;
        }
        else
            zero->next = twohead->next;
        two->next = nullptr;
        return zerohead->next;
    }
};
int main()
{
}