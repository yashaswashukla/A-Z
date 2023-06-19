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
        struct Node *prev = nullptr, *curr = head, *nx = nullptr;
        while (curr)
        {
            nx = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nx;
        }
        return prev;
    }
};
int main()
{
}