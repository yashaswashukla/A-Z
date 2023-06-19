/*
Gfg:https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
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
    bool isPalindrome(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        fast = slow->next;
        slow = head;
        while (fast)
        {
            if (fast->data != slow->data)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
int main()
{
}