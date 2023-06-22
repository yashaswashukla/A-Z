/*
Gfg:https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *deleteMid(Node *head)
    {
        if (!head or !head->next)
            return nullptr;
        Node *fast = head, *slow = head, *prev = head;
        if (!head->next)
            return nullptr;
        while (fast and fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        return head;
    }
};
class leetSolution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head or !head->next)
            return nullptr;
        ListNode *fast = head, *slow = head, *prev = head;
        while (fast and fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        return head;
    }
};
int main()
{
}