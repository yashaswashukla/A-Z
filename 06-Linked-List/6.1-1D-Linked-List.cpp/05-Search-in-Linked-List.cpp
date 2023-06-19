/*
Gfg:https://practice.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchKey(int n, struct Node *head, int key)
    {
        struct Node *ptr = head;
        while (ptr)
        {
            if (ptr->data == key)
                return true;
            ptr = ptr->next;
        }
        return false;
    }
};
int main()
{
}