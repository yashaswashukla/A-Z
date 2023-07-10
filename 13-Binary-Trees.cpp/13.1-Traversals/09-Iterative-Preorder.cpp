/*
Gfg:https://practice.geeksforgeeks.org/problems/preorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> preOrder(Node *root)
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
                ans.push_back(node->data);
                st.push(node);
                node = node->left;
            }
            else
            {
                node = st.top();
                st.pop();
                node = node->right;
            }
        }
        return ans;
    }
};
int main()
{
}