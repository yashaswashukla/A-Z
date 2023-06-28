/*
Gfg:https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
Leetcode:https://leetcode.com/problems/rotate-list/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        Node *fast = head, *slow = head;
        while (fast->next)
            fast = fast->next;
        k--;
        while (k--)
            slow = slow->next;
        Node *newhead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newhead;
    }
};
class leetSolution
{
public:
    int len(ListNode *head)
    {
        ListNode *ptr = head;
        int count = 0;
        while (ptr)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        k = k % len(head);
        if (!k)
            return head;
        ListNode *fast = head, *slow = head;
        while (k--)
            fast = fast->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *newhead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newhead;
    }
};
int main()
{
}