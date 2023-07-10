/*
Gfg:https://practice.geeksforgeeks.org/problems/binary-tree-representation/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    node *build(int idx, vector<int> &vec)
    {
        if (idx >= vec.size())
            return nullptr;
        node *root = new node(vec[idx]);
        root->left = build(2 * idx + 1, vec);
        root->right = build(2 * idx + 2, vec);
        return root;
    }
    void create_tree(node * &root0, vector<int> &vec)
    {
        root0 = build(0, vec);
    }
};
int main()
{
}