/*
Gfg:https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&category[]=Linked+List&sortBy=submissions
Leetcode:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getNthFromLast(Node *head, int n)
    {
        Node *fast = head, *slow = head;
        while (n--)
        {
            fast = fast->next;
            if (n > 0 and !fast)
                return -1;
        }

        if (!fast)
            return head->data;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }
};
class leetSolution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;
        ListNode *fast = head, *slow = head;

        while (n--)
            fast = fast->next;
        if (!fast)
            return head->next;

        while (fast and fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
int main()
{
}