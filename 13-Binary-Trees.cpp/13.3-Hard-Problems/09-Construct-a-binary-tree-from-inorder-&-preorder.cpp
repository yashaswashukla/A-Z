/*
Gfg:https://practice.geeksforgeeks.org/problems/construct-tree-1/1
Leetcode:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *helper(int instart, int prestart, int inend, int n, int inorder[], int preorder[])
    {
        if (prestart >= n or instart > inend)
            return nullptr;

        Node *root = new Node(preorder[prestart]);
        int curridx = 0;
        for (int i = instart; i <= inend; i++)
            if (root->data == inorder[i])
                curridx = i;

        root->left = helper(instart, prestart + 1, curridx - 1, n, inorder, preorder);
        root->right = helper(curridx + 1, prestart + curridx - instart + 1, inend, n, inorder, preorder);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        return helper(0, 0, n - 1, n, in, pre);
    }
};
int main()
{
}