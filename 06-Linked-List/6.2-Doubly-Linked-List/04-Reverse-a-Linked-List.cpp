/*
Gfg:https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *reverseDLL(Node *head)
    {
        if (!head or !head->next)
            return head;
        Node *ptr = head, *temp = nullptr;
        while (ptr)
        {
            temp = ptr->prev;
            ptr->prev = ptr->next;
            ptr->next = temp;
            ptr = ptr->prev;
        }
        return temp;
    }
};
int main()
{
}