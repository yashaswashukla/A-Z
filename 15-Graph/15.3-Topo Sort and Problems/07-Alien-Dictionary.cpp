/*
GFG: https://practice.geeksforgeeks.org/problems/alien-dictionary/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        vector<int> inDegree(K, 0);
        string ans;
        queue<int> q;
        for (int i = 0; i < N - 1; i++)
        {
            int x = min(dict[i].length(), dict[i + 1].length());

            for (int j = 0; j < x; j++)
                if (dict[i][j] != dict[i + 1][j])
                {
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
        }
        for (int i = 0; i < K; i++)
            for (auto x : adj[i])
                inDegree[x]++;
                
        for (int i = 0; i < K; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans += 'a' + node;
            q.pop();

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        return ans;
    }
};
int main()
{
}