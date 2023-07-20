/*
Gfg:https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
Leetcode:https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
public:
    vector<int> serialize(Node *root)
    {
        vector<int> tree;
        queue<Node *> q;
        q.push(root);
        tree.push_back(root->data);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
            {
                tree.push_back(node->left->data);
                q.push(node->left);
            }
            else
                tree.push_back(-1);

            if (node->right)
            {
                tree.push_back(node->right->data);
                q.push(node->right);
            }
            else
                tree.push_back(-1);
        }
        return tree;
    }

    Node *deSerialize(vector<int> &A)
    {
        int i = 0;
        Node *root = new Node(A[i++]);
        queue<Node *> q;
        q.push(root);
        while (!q.empty() and i < A.size())
        {
            Node *node = q.front();
            q.pop();
            if (A[i] != -1)
            {
                node->left = new Node(A[i]);
                q.push(node->left);
            }
            i++;
            if (A[i] != -1)
            {
                node->right = new Node(A[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
class leetSolution
{
public:
    string serialize(TreeNode *root)
    {
        string tree = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                temp += "," + to_string(node->left->val);
                q.push(node->left);
            }
            else
                temp += "#";

            if (node->right)
            {
                temp += to_strin(node->right->val);
                q.push(node->right);
            }
            else
                temp += "#";
        }
        for (auto x : temp)
            cout << x << " ";
        cout << endl;
        return tree;
    }

    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            getline(ss, str, ',');
            if (str != "#")
            {
                node->left = new TreeNode stoi(str);
                q.push(node->left);
            }

            getline(ss, str, ',');
            if (str != "#")
            {
                node->right = new TreeNode stoi(str);
                q.push(node->right);
            }
        }
        return root;
    }
};
int main()
{
}