/*
GFG:https://practice.geeksforgeeks.org/problems/course-schedule/1
Leetcode: https://leetcode.com/problems/course-schedule/
*/
#include <bits/stdc++.h>
using namespace std;
class gfgSolution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
    {
        // code here
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < n; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        if (ans.size() == n)
            return ans;
        return {};
    }
};
class leetcodeSolution
{
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        int m = prerequisites.size();
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < n; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto x : adj[node])
            {
                inDegree[x]--;
                if (!inDegree[x])
                    q.push(x);
            }
        }
        if (ans.size() == n)
            return true;
        return false;
    }
};
int main()
{
}