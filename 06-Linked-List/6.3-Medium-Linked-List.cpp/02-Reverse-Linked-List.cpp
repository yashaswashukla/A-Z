/*
Gfg:https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        if (!head or !head->next)
            return head;

        struct Node *rest = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return rest;
    }
};
int main()
{
}