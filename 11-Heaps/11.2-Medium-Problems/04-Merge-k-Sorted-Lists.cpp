/*
Gfg:https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
Leetcode:https://leetcode.com/problems/merge-k-sorted-lists/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node *mergeKLists(Node *arr[], int K)
    {
        if (arr == nullptr or k == 0)
            return nullptr;

        Node *head = new Node(0), *temp = head;

        while (true)
        {
            int p = 0;
            for (int i = 0; i < k; i++)
                if (list[p] == nullptr or (list[i] and list[p]->data > list[i]->data))
                    p = i;
            if (!list[p])
                break;
            temp->next = list[p];
            temp = temp->next;
            list[p] = list[p]->next;
        }
        return head->next;
    }
};
class comp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class betterSolution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (!n)
            return nullptr;

        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        for (auto list : lists)
        {
            if (list)
                pq.push(list);
        }

        ListNode *ans = new ListNode(0), *temp = ans;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            temp->next = node;
            temp = temp->next;

            if (node->next)
                pq.push(node->next);
        }
        return ans->next;
    }
};

class bestSolution
{
public:
    ListNode *mergeLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (!n)
            return nullptr;
        return mergeSort(lists, 0, n - 1);
    }
    ListNode *mergeSort(vector<ListNode *> list, int start, int end)
    {
        if (start == end)
            return list[start];

        int mid = start + (end - start) / 2;

        ListNode *left = mergeSort(list, start, mid);
        ListNode *right = mergeSort(list, mid + 1, end);

        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *ans = new ListNode(0), *temp = ans;

        while (left and right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left)
            temp->next = left;
        if (right)
            temp->next = right;
        return ans->next;
    }
};
int main()
{
}