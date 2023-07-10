/*
Gfg:https://practice.geeksforgeeks.org/problems/inorder-traversal/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        helper(root->left, ans);
        ans.push_back(root->data);
        helper(root->right, ans);
    }
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
int main()
{
}