/*
Gfg:https://practice.geeksforgeeks.org/problems/introduction-to-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        if (!arr.size())
            return nullptr;
        Node *head = new Node(arr[0]);
        Node *temp = head;
        for (int i = 1; i < arr.size(); i++)
        {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
}