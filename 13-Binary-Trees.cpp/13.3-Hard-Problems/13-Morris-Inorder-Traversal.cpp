/*
Gfg:https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> inorder;
        Node *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *next = curr->left;
                while (next->right and next->right != curr)
                    next = next->right;
                if (!next->right)
                {
                    next->right = curr;
                    curr = curr->left;
                }
                else
                {
                    next->right = nullptr;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
int main()
{
}