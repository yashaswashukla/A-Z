/*
Gfg:https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
Leetcode:https://leetcode.com/problems/odd-even-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *evenhead = new Node(-1), *oddhead = new Node(-1);

        Node *ptr = head, *even = evenhead, *odd = oddhead;
        while (ptr)
        {
            if (ptr->data % 2)
            {
                odd->next = ptr;
                odd = ptr;
            }
            else
            {
                even->next = ptr;
                even = ptr;
            }
            ptr = ptr->next;
        }
        if (!evenhead->next)
            return oddhead;
        even->next = oddhead->next;
        odd->next = nullptr;
        return evenhead->next;
    }
};
class leetSolution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *odd = head, *even = head->next, *evenhead = even;
        while (odd->next and even->next)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
int main()
{
}