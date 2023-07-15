/*
Gfg:https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
Leetcode:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        if (!root)
            return nullptr;
        if(root->data == n1 or root->data == n2)
            return root;
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        if(left and right)
            return root;
        return left ? left : right;
    }
};
int main()
{
}