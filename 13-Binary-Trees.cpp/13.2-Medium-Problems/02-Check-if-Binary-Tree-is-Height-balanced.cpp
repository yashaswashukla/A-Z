/*
Gfg:https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
Leetcode:https://leetcode.com/problems/balanced-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int height(Node *root)
    {
        if (!root)
            return 0;
        int left = height(root->left), right = height(root->right);
        if (left == -1 or right == -1)
            return -1;
        return abs(left - right) <= 1 ? max(left, right) + 1 : -1;
    }
    bool isBalanced(Node *root)
    {
        return height(root) != -1;
    }
};
int main()
{
}