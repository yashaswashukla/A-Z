/*
Gfg:https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void addNode(Node *head, int pos, int data)
    {
        if (!head)
            return;

        Node *temp = head;
        while (pos--)
            temp = temp->next;
        Node *node = new Node(data);

        if (!temp->next)
        {
            temp->next = node;
            node->prev = temp;
            node->next = nullptr;
            return;
        }

        Node *nx = temp->next;
        temp->next = node;
        node->next = nx;
        nx->prev = temp;
        node->prev = temp;
        return;
    }
};
int main()
{
}