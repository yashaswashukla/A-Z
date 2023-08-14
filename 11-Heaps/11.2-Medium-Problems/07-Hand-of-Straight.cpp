/*
Gfg:https://practice.geeksforgeeks.org/problems/hands-of-straights/1
Leetcode:https://leetcode.com/problems/hand-of-straights/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        // Insert all the elements in the heap
        for (auto val : hand)
            pq.push(val);

        while (!pq.empty())
        {
            vector<int> rem; // Storing the duplicate elements

            int group = groupSize - 1; // Current group size, -1 because we take out one element in the beginning

            int prev = pq.top();
            pq.pop(); // Taking out the first element of the group

            while (!pq.empty() and group)
            {
                if (pq.top() == prev + 1) // Checking the criteria of inclusion
                {
                    prev = pq.top();
                    group--; // If included then reduce the size of current group
                }
                else
                    rem.push_back(pq.top()); // If not included then simply put it in remaining elements
                pq.pop();
            }

            for (auto x : rem)
                pq.push(x); // Push the remaining elements in the heap

            if (group) // If the size of the current group is not equal to the required group size then return false
                return false;
        }
        return true; // If all the groups meet the requirement then just return true
    }
};
int main()
{
}