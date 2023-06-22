/*
Gfg:https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Node *reverse(struct Node *head)
    {
        if (!head or !head->next)
            return head;
        struct Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        struct Node *ans = new struct Node(-1), *ptr = ans;

        while (first or second or carry)
        {
            int sum = 0;
            if (first)
            {
                sum += first->data;
                first = first->next;
            }

            if (second)
            {
                sum += second->data;
                second = second->next;
            }

            sum += carry;
            ptr->next = new struct Node(sum % 10);
            carry = sum / 10;
            ptr = ptr->next;
        }
        ans = reverse(ans->next);
        return ans;
    }
};
int main()
{
}