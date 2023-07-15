/*
Gfg:https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
Leetcode:https://leetcode.com/problems/same-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if (!r1 and !r2)
            return true;
        if (!r1 or !r2)
            return false;
        if (!isIdentical(r1->left, r2->left))
            return false;
        if (r1->data != r2->data)
            return false;
        return isIdentical(r1->right, r2->right);
    }
};
int main()
{
}