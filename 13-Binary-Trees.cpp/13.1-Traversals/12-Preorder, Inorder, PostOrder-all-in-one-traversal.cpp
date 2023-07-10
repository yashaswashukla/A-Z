/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
    {
        if (!root)
            return {};
        vector<int> preorder, inorder, postorder;
        stack<pair<BinaryTreeNode<int> *, int>> st;
        st.push({root, 1});
        while (!st.empty())
        {
            BinaryTreeNode<int> *node = st.top().first;
            int num = st.top().second;
            st.pop();
            if (num == 1)
            {
                preorder.push_back(node->data);
                st.push({node, num + 1});
                if (node->left)
                    st.push({node->left, 1});
            }
            else if (num == 2)
            {
                inorder.push_back(node->data);
                st.push({node, num + 1});
                if (node->right)
                    st.push({node->right, 1});
            }
            else
                postorder.push_back(node->data);
        }
        return {inorder, preorder, postorder};
    }
};
int main()
{
}