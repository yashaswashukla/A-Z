/*
Gfg:https://practice.geeksforgeeks.org/problems/preorder-traversal/1
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
        ans.push_back(root->data);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
int main()
{
}