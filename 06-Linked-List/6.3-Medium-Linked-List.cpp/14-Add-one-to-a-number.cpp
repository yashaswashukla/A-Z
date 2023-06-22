/*
Gfg:https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
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

    Node *addOne(Node *head)
    {
        if (!head)
            return head;
        head = reverse(head);
        int carry = 1;
        Node *ans = new Node(-1), *temp = ans;
        Node *ptr = head;

        while (carry or ptr)
        {
            int sum = 0;
            if (ptr)
            {
                sum += ptr->data;
                ptr = ptr->next;
            }
            sum += carry;
            temp->next = new Node(sum % 10);
            carry = sum / 10;
            temp = temp->next;
        }
        ans = reverse(ans->next);
        return ans->next;
    }
};
int main()
{
}