/*
Gfg:https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class rightViewRecSolution
{
public:
    void helper(Node *root, int level, vector<int> &ans)
    {
        if (!root)
            return;
        if (level >= ans.size())
            ans.push_back(root->data);
        helper(root->right, level + 1, ans);
        helper(root->left, level + 1, ans);
    }
    vector<int> rightView(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};
class rightViewIterSolution
{
public:
    vector<int> rightView(Node *root)
    {
        if (!root)
            return {};
        queue<Node *> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (!i)
                    ans.push_back(node->data);
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};
class leftViewRecSolution
{
public:
    void helper(Node *root, int level, vector<int> &ans)
    {
        if (!root)
            return;
        if (level >= ans.size())
            ans.push_back(root->data);
        helper(root->left, level + 1, ans);
        helper(root->right, level + 1, ans);
    }
    vector<int> leftView(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};
class leftViewIterSolution
{
public:
    vector<int> leftView(Node *root)
    {

        if (!root)
            return {};
        queue<Node *> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (!i)
                    ans.push_back(node->data);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
int main()
{
}