/*
Gfg:https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class geekSolution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *ans = new Node(-1), *temp = ans;
        unordered_map<int, bool> hash;
        while (head2)
        {
            hash[head2->data] = true;
            head2 = head2->next;
        }
        while (head1)
        {
            if (hash[head1->data])
            {
                temp->next = head1;
                temp = temp->next;
            }
            head1 = head1->next;
        }
        temp->next = NULL;
        return ans->next;
    }
};
class leetSolution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        ListNode *one = head1, *two = head2;
        bool switch = false;
        while (one != two)
        {
            if (one)
                one = one->next;
            else
                one = head2;

            if (two)
                two = two->next;
            else
                two = head1;
        }
        return one;
    }
};
int main()
{
}