/*
Gfg:https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
Leetcode:https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        Node *node = nullptr;
        vector<int> ans;
        queue<Node *> q;
        unordered_map<Node *, Node *> hash;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->data == target)
                    node = temp;

                if (temp->left)
                {
                    q.push(temp->left);
                    hash[temp->left] = temp;
                }
                if (temp->right)
                {
                    q.push(temp->right);
                    hash[temp->right] = temp;
                }
            }
        }
        unordered_map<int, int> vis;
        q.push(node);
        while (k-- and !q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *temp = q.front();
                q.pop();
                vis[temp->data] = 1;
                if (hash[temp] and !vis[hash[temp]->data])
                    q.push(hash[temp]);
                if (temp->left and !vis[temp->left->data])
                    q.push(temp->left);
                if (temp->right and !vis[temp->right->data])
                    q.push(temp->right);
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};
int main()
{
}