/*
Gfg:https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
Leetcode:https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *prev = nullptr;
    void flatten(Node *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
int main()
{
}