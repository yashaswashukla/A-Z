/*
Gfg:https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (!root)
            return {};
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        map<int, int> hash;

        while (!q.empty())
        {
            Node *node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            hash[vertical] = node->data;
            if (node->left)
                q.push({node->left, vertical - 1});
            if (node->right)
                q.push({node->right, vertical + 1});
        }
        vector<int> ans;
        for (auto x : hash)
            ans.push_back(x.second);
        return ans;
    }
};
int main()
{
}