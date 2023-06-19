/*
Gfg: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countNodesinLoop(struct Node *head)
    {
        struct Node *fast = head, *slow = head;
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
                break;
            }
        }
        if (!fast or !fast->next)
            return 0;
        int len = 0;
        do
        {
            fast = fast->next;
            len++;
        } while (fast != slow);
        return len;
    }
};
int main()
{
}