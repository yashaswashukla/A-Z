/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class leetSolution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *ptr = dummy;

        while (ptr)
        {
            ListNode *node = ptr;
            for (int i = 0; i < k and node; i++)
                node = node->next;
            if (!node)
                break;

            ListNode *prev = nullptr, *curr = ptr->next, *nx = nullptr;
            for (int i = 0; i < k; i++)
            {
                nx = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nx;
            }
            ListNode *tail = ptr->next;
            tail->next = curr;
            ptr->next = prev;
            ptr = tail;
        }
        return dummy->next;
    }
};
class geekSolution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (!head or !k)
            return head;
        int i = 0;
        struct node *prev = nullptr, *curr = head, *nx = nullptr;
        while (i < k and curr)
        {
            nx = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nx;
            i++;
        }

        if (nx)
            head->next = reverse(nx, k);
        return prev;
    }
};
int main()
{
}