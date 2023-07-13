/*
Gfg:https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
Leetcode:https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int height(struct Node *root)
    {
        if (!root)
            return 0;
        int left = height(root->left), right = height(root->right);
        return max(left, right) + 1;
    }
};
int main()
{
}