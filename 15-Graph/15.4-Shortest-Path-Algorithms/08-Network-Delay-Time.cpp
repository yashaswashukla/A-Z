/*
Gfg:
Leetcode:https://leetcode.com/problems/network-delay-time/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times)
            adj[it[0]].push_back({it[1], it[2]});
        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        set<pair<int, int>> hash;
        hash.insert({0, k});

        while (!hash.empty())
        {
            auto it = *(hash.begin());
            hash.erase(it);
            int prevTime = it.first, node = it.second;

            for (auto x : adj[node])
            {
                int next = x.first, cost = x.second;
                if (time[next] > prevTime + cost)
                {
                    if (time[next] != 1e9)
                        hash.erase({time[next], next});
                    time[next] = prevTime + cost;
                    hash.insert({time[next], next});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (time[i] == 1e9)
                return -1;
            ans = max(time[i], ans);
        }
        return ans;
    }
};
int main()
{
}