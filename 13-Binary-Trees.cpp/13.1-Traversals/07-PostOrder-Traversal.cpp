/*
Gfg:https://practice.geeksforgeeks.org/problems/postorder-traversal/1
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
        helper(root->right, ans);
        ans.push_back(root->data);
    }
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
int main()
{
}