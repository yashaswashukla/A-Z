/*
Gfg:https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *merge(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        Node *ans = new Node(0), *temp = ans;

        while (l1 and l2)
        {
            if (l1->data < l2->data)
            {
                temp->bottom = l1;
                l1 = l1->bottom;
            }
            else
            {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }

        if (l1)
            temp->bottom = l1;
        if (l2)
            temp->bottom = l2;

        return ans->bottom;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if (!root or !root->next)
            return root;

        root->next = flatten(root->next);

        root = merge(root, root->next);
        return root;
    }
};
int main()
{
}