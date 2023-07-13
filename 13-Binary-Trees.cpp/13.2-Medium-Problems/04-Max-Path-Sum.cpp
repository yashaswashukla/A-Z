/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
Leetcode:https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans = INT_MIN;
    int helper(Node *root)
    {
        if (!root)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int choose_one = max(root->data, max(left, right) + root->data);
        int choose_two = max(choose_one, root->data + left + right);
        ans = max(ans, choose_two);
        return choose_one;
    }
    int findMaxSum(Node *root)
    {
        helper(root);
        return ans;
    }
};
int main()
{
}