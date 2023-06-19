/*
Gfg:https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        if (!head)
            return nullptr;
        if (x == 1)
            return head->next;
        Node *temp = head, *prev = head;
        x--;
        while (x--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
int main()
{
}