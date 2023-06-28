/*
Gfg:https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
Leetcode:https://leetcode.com/problems/copy-list-with-random-pointer/
*/
#include <bits/stdc++.h>
using namespace std;
class naiveSolution
{
public:
    Node *copyList(Node *head)
    {
        unordered_map<Node *, Node *> hash;
        Node *ptr = head;
        while (ptr)
        {
            hash[ptr] = new Node(ptr->data);
            ptr = ptr->next;
        }

        ptr = head;

        while (ptr->next)
        {
            hash[ptr]->next = hash[ptr->next];
            hash[ptr]->arb = hash[ptr->arb];
            ptr = ptr->next;
        }
        return hash[head];
    }
};
class optimalSolution
{
public:
    Node *copyList(Node *head)
    {
        Node *ptr = head;
        while (ptr)
        {
            Node *nx = ptr->next;
            ptr->next = new Node(ptr->data);
            ptr->next->next = nx;
            ptr = nx;
        }
        ptr = head;
        while (ptr)
        {
            if (ptr->arb)
            {
                Node *clone = ptr->next;
                clone->arb = ptr->arb->next;
            }
            ptr = ptr->next->next;
        }

        Node *ans = new Node(-1), *temp = ans;
        ptr = head;
        while (ptr)
        {
            if (ptr->next)
            {
                temp->next = ptr->next;
                ptr->next = ptr->next->next;
                temp = temp->next;
            }
            ptr = ptr->next;
        }
        return ans->next;
    }
};
int main()
{
}