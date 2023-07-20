/*
Gfg:https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        vector<int> preorder;
        Node *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                preorder.push_back(curr->data);
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
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    next->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
int main()
{
}