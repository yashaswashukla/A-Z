/*
Gfg:https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countNodes(Node *root)
    {
        if(!root)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
};
int main()
{
}