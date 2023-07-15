/*
Gfg:https://practice.geeksforgeeks.org/problems/children-sum-parent/1
Leetcode:https://leetcode.com/problems/root-equals-sum-of-children/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int isSumProperty(Node *root)
    {
        if (!root)
            return 1;
        if (!root->left and !root->right)
            return 1;
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
        if (root->data != left + right)
            return false;
        return isSumProperty(root->left) and isSumProperty(root->right);
    }
};
int main()
{
}