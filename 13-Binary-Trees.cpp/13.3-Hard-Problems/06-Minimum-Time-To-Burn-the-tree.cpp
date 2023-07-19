/*
Gfg:https://practice.geeksforgeeks.org/problems/burning-tree/1
Leetcode:https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTime(Node *root, int target)
    {
        Node *start = nullptr;
        queue<Node *> q;
        unordered_map<Node *, Node *> parent;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *node = q.front();
                q.pop();
                if (node->data == target)
                    start = node;

                if (node->left)
                {
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if (node->right)
                {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_map<Node *, int> vis;
        q.push(start);
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *node = q.front();
                vis[node] = 1;
                q.pop();
                if (node->left and !vis[node->left])
                    q.push(node->left);
                if (node->right and !vis[node->right])
                    q.push(node->right);
                if (parent[node] and !vis[parent[node]])
                    q.push(parent[node]);
            }
            time++;
        }
        return time - 1;
    }
};
int main()
{
}