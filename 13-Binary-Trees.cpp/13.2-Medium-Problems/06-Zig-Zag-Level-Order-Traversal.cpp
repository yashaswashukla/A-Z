/*
Gfg:https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
Leetcode:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        deque<Node *> q;
        bool rtl = false;
        q.push_front(root);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                if (rtl)
                {
                    Node *node = q.front();
                    ans.push_back(node->data);
                    q.pop_front();
                    if (node->right)
                        q.push_back(node->right);
                    if (node->left)
                        q.push_back(node->left);
                }
                else
                {

                    Node *node = q.back();
                    ans.push_back(node->data);
                    q.pop_back();
                    if (node->left)
                        q.push_front(node->left);
                    if (node->right)
                        q.push_front(node->right);
                }
            }
            rtl = !rtl;
        }

        return ans;
    }
};
int main()
{
}