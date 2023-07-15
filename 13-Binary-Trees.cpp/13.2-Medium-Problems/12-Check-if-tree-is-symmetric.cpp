/*
Gfg:
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class dfsSolution
{
public:
    bool helper(struct Node *r1, struct Node *r2)
    {
        if (!r1 or !r2)
            return r1 == r2;
        if (r1->data != r2->data)
            return false;
        return helper(r1->left, r2->right) and helper(r1->right, r2->left);
    }
    bool isSymmetric(struct Node *root)
    {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};
class bfsSolution
{
public:
    bool isSymmetric(struct Node *root)
    {
        if (!root)
            return true;
        queue<Node *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() and !q2.empty())
        {
            Node *r1 = q1.front(), *r2 = q2.front();
            q1.pop();
            q2.pop();
            if (!r1 and !r2)
                continue;
            if (!r1 or !r2)
                return false;

            if (r1->data != r2->data)
                return false;
            q1.push(r1->left);
            q1.push(r1->right);
            q2.push(r2->right);
            q2.push(r2->left);
        }
        return q1.size() == q2.size();
    }
};
int main()
{
}