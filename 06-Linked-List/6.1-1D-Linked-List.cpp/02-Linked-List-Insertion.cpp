/*
Gfg:https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *insertAtBegining(Node *head, int x)
    {
        Node *newhead = new Node(x);
        newhead->next = head;
        return newhead;
    }

    Node *insertAtEnd(Node *head, int x)
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node(x);
        return head;
    }
};
int main()
{
}