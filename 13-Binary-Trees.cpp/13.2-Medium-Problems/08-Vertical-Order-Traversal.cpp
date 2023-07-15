/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {
        map<int, vector<int>> hash;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int col = q.front().second;
            hash[col].push_back(node->data);
            q.pop();
            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }
        vector<int> ans;
        for (auto x : hash)
            for (auto k : x.second)
                ans.push_back(k);
        return ans;
    }
};
int main()
{
}