/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1
Leetcode:https://leetcode.com/problems/maximum-width-of-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getMaxWidth(Node *root)
    {
        int ans = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            ans = max(size, ans);
            while (size--)
            {
                Node *node = q.front();
                q.pop();
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