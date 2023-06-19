/*
Gfg: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getMiddle(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
};
int main()
{
}