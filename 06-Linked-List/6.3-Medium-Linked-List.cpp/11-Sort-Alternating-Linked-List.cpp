/*
Gfg:https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
public:
    Node *reverse(Node *head)
    {
        if (!head or !head->next)
            return head;
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    void sort(Node **head)
    {
        if (!*head or !(*head)->next)
            return;
        Node *inc = *head, *dec = inc->next;

        Node *first = inc, *sec = dec;
        while (inc->next and dec->next)
        {
            inc->next = dec->next;
            inc = inc->next;

            dec->next = inc->next;
            dec = dec->next;
        }
        inc->next = nullptr;
        sec = reverse(sec);
        Node *ans = new Node(-1);
        Node *temp = ans;

        while (first and sec)
        {
            if (first->data <= sec->data)
            {
                temp->next = first;
                first = first->next;
            }
            else
            {
                temp->next = sec;
                sec = sec->next;
            }
            temp = temp->next;
        }
        if (first)
            temp->next = first;
        if (sec)
            temp->next = sec;

        *head = ans->next;
    }
};
class leetSolution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new Node(-1), *temp = ptr;
        while (l1 and l2)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1)
            temp->next = l1;
        if (l2)
            temp->next = l2;
        return ptr->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head or !head->next)
            return head;
        ListNode *prev = nullptr, *fast = head, *slow = head;
        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1, l2);
    }
};
int main()
{
}