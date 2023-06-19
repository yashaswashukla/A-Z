/*
Gfg:https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *deleteNode(Node *head_ref, int x)
    {
        if (x == 1)
            return head_ref->next;
        Node *temp = head_ref;
        x -= 2;
        while (x--)
            temp = temp->next;

        Node *nx = temp->next->next;
        temp->next = nx;
        if (nx)
            nx->prev = temp;
        return head_ref;
    }
};
int main()
{
}