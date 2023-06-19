/*
Gfg:https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/0
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getCount(struct Node *head)
    {
        struct Node *temp = head;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
};
int main()
{
}