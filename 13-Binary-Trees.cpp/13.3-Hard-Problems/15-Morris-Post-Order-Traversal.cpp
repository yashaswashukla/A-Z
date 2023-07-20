/*
Gfg:https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> postorder;
        Node *curr = root;
        while (curr)
        {
            if (!curr->right)
            {
                postorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                Node *next = curr->right;
                while (next->left and next->left != curr)
                    next = next->left;

                if (!next->left)
                {
                    next->left = curr;
                    postorder.push_back(curr->data);
                    curr = curr->right;
                }
                else
                {
                    next->left = nullptr;
                    curr = curr->left;
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};
int main()
{
}