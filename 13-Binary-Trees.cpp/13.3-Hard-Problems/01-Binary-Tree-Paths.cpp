/*
Gfg:https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1
Leetcode:https://leetcode.com/problems/binary-tree-paths/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(Node *root, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (!root)
            return;
        temp.push_back(root->data);
        if (!root->left and !root->right)
            ans.push_back(temp);

        helper(root->left, ans, temp);
        helper(root->right, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root, ans, temp);
        return ans;
    }
};
class leetSolution
{
public:
    vector<string> ans;
    void helper(TreeNode *root, string temp)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp += to_string(root->val) + "->";
        helper(root->left, temp);
        helper(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string temp = "";
        helper(root, temp);
        return ans;
    }
};
int main()
{
}