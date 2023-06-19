/*
Gfg:https://practice.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        if (!arr.size())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *nx = new Node(arr[i]);
            temp->next = nx;
            nx->prev = temp;
            temp = nx;
        }
        return head;
    }
};
int main()
{
}