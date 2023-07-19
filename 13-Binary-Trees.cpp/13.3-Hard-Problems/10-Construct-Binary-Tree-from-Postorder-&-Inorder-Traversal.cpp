/*
Gfg:https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
Leetcode:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *helper(int postend, int instart, int inend, int inorder[], int postorder[])
    {
        if (postend < 0 or instart > inend)
            return nullptr;

        Node *root = new Node(postorder[postend]);

        int idx = instart;
        while (idx < inend)
        {
            if (inorder[idx] == root->data)
                break;
            idx++;
        }

        root->left = helper(postend - (inend - idx + 1), instart, idx - 1, inorder, postorder);
        root->right = helper(postend - 1, idx + 1, inend, inorder, postorder);
        return root;
    }
    Node *buildTree(int in[], int post[], int n)
    {
        return helper(n - 1, 0, n - 1, in, post);
    }
};
int main()
{
}