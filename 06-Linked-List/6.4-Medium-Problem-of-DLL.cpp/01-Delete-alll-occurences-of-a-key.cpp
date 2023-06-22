/*
Gfg:https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head_ref, int x)
    {
        if (!(*head_ref))
            return;

        struct Node *ptr = *head_ref;

        while (ptr)
        {
            if (ptr->data == x)
            {
                if (!ptr->prev)
                {
                    *head_ref = ptr->next;
                    ptr = *head_ref;
                }
                else
                {
                    struct Node *last = ptr->prev, *nx = ptr->next;
                    last->next = nx;
                    if (nx)
                        nx->prev = last;
                    ptr = nx;
                }
            }
            else
                ptr = ptr->next;
        }
    }
};
int main()
{
}