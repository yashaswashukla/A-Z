/*
Gfg:https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
            meetings.push_back({start[i], end[i]});
        sort(meetings.begin(), meetings.end(), comp);
        int count = 0, last = 0;
        for (auto x : meetings)
        {
            int begin = x.first, finish = x.second;
            if (x.first > last)
            {
                last = finish;
                count++;
            }
        }
        return count;
    }
};
int main()
{
}