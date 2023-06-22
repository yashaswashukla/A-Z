/*
Gfg:https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        if (!head->next)
            return ans;

        Node *left = head, *right = head;
        
        while (right->next)
            right = right->next;
        while (left != right)
        {
            int sum = left->data + right->data;

            if (sum == target)
            {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
                left = left->next;
            else
                right = right->prev;
        }
        return ans;
    }
};
int main()
{
}