/*
Gfg:https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> postOrder(Node *root)
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
                Node *temp = st.top()->right;
                if (!temp)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while (!st.empty() and temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else
                    node = temp;
            }
        }
        return ans;
    }
};
int main()
{
}