/*
Gfg:
Leetcode:https://leetcode.com/problems/linked-list-cycle-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        Node *fast = head, *slow = head;
        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
int main()
{
}