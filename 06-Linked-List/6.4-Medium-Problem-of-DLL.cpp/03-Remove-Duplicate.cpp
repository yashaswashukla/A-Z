/*
Gfg:https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        if (!head or !head->next)
            return head;

        struct Node *ptr = head;
        while (ptr and ptr->next)
        {
            struct Node *temp = ptr;
            while (temp and temp->data == ptr->data)
                temp = temp->next;
            ptr->next = temp;
            if (temp)
                temp->prev = ptr;
            ptr = temp;
        }
        return head;
    }
};
int main()
{
}