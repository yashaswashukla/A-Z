/*
Gfg:https://practice.geeksforgeeks.org/problems/level-order-traversal/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> levelOrder(Node *node)
    {
        if (!node)
            return };
        vector<int> ans;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return ans;
    }
};
int main()
{
}