/*
Gfg:
Leetcode:https://leetcode.com/problems/count-complete-tree-nodes/description/
*/
#include <bits/stdc++.h>
using namespace std;
class naiveSolution
{
public:
    /*
    Naive, because we know that this is a complete binary tree and we have to use the property
    of a complete binary tree.
    */
    // O(N)
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
};
class optimizedSolution
{
public:
    int findHeightLeft(TreeNode *cur)
    {
        int hght = 0;
        while (cur)
        {
            hght++;
            cur = cur->left;
        }
        return hght;
    }
    int findHeightRight(TreeNode *cur)
    {
        int hght = 0;
        while (cur)
        {
            hght++;
            cur = cur->right;
        }
        return hght;
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);

        return 1 + leftNodes + rightNodes;
    }
};
int main()
{
}