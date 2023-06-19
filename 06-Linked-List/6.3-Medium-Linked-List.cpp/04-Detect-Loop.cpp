/*
Gfg:https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&category[]=Linked+List&sortBy=submissions
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool detectLoop(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
                return true;
        }
        return false;
    }
};
int main()
{
}