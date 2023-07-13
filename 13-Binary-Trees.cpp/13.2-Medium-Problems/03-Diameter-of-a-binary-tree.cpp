/*
Gfg:https://leetcode.com/problems/diameter-of-binary-tree/
Leetcode:https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans = 0;
    int height(Node *root)
    {
        if (!root)
            return 0;
        int left = height(root->left), right = height(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
    int diameter(Node *root)
    {
        height(root);
        return ans;
    }
};
int main()
{
}