/*
Gfg:https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class iterativeSolution
{
public:
    void addLeft(Node *root, vector<int> &ans)
    {
        Node *node = root->left;
        while (node)
        {
            if (node->left or node->right)
                ans.push_back(node->data);
            if (node->left)
                node = node->left;
            else
                node = node->right;
        }
    }
    void addLeaf(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        addLeaf(root->left, ans);
        if (!root->left and !root->right)
            ans.push_back(root->data);
        addLeaf(root->right, ans);
    }
    void addRight(Node *root, vector<int> &ans)
    {
        Node *node = root->right;
        vector<int> temp;
        while (node)
        {
            if (node->left or node->right)
                temp.push_back(node->data);
            if (node->right)
                node = node->right;
            else
                node = node->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        if (root->left or root->right)
            ans.push_back(root->data);
        addLeft(root, ans);
        addLeaf(root, ans);
        addRight(root, ans);
        return ans;
    }
};
class recSolution
{
public:
    vector<int> ans;
    void addLeft(Node *root)
    {
        if (!root or (!root->left and !root->right))
            return;
        ans.push_back(root->data);
        if (root->left)
            addLeft(root->left);
        else
            addLeft(root->right);
    }
    void addLeaf(Node *root)
    {
        if (!root)
            return;
        addLeaf(root->left);
        if (!root->left and !root->right)
            ans.push_back(root->data);
        addLeaf(root->right);
    }
    void addRight(Node *root)
    {
        if (!root or (!root->left and !root->right))
            return;
        if (root->right)
            addRight(root->right);
        else
            addRight(root->left);
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        if (!root)
            return {};
        ans.push_back(root->data);
        addLeft(root->left);
        addLeaf(root->left);
        addLeaf(root->right);
        addRight(root->right);
        return ans;
    }
};
int main()
{
}