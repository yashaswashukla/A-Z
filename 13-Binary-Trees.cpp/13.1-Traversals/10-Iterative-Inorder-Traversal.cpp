/*
Gfg:https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        stack<Node *> st;
        Node *node = root;
        while (!st.empty() or node)
        {
            if (node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};
int main()
{
}