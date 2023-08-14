/*
Gfg:https://practice.geeksforgeeks.org/problems/task-scheduler/1
Leetcode:https://leetcode.com/problems/task-scheduler/solutions/3280549/full-explanation-using-priority-queue-and-formula-based-approach/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int k)
    {
        vector<int> freq(26, 0);
        for (auto task : tasks)
            freq[task - 'A']++; // Count the number of times
        priority_queue<int> pq;

        for (auto x : freq)
            if (x)
                pq.push(x);

        int time = 0; // counting the total time required

        while (!pq.empty())
        {
            vector<int> remaining; // Will store the elements with remaining frequency after completing one cycle

            int cycleLen = k + 1;
            // One entire cycle
            while (cycleLen and !pq.empty())
            {
                // Taking out elements one by one and decreasing the frequency
                int max_freq = pq.top();
                pq.pop();
                if (max_freq > 1) // If any element has remaining frequency adding that too
                    remaining.push_back(max_freq - 1);
                time++;
                cycleLen--;
            }

            for (auto rem : remaining)
                pq.push(rem); // Push back the remaining tasks

            if (!pq.empty())      // If the heap is not empty that means there are elements left behind, if there is any idle time we will have to add it
                time += cycleLen; // Adding the idle time
        }
        return time;
    }
};
class bestSolution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (auto task : tasks)
        {
            freq[task - 'A']++;
            maxFreq = max(maxFreq, freq[task - 'A']);
        }

        int count = 0;
        for (auto x : freq)
            if (x == maxFreq)
                count++;
        int N = tasks.size();
        return max(N, (maxFreq - 1) * (n + 1) + count);
    }
};
int main()
{
}