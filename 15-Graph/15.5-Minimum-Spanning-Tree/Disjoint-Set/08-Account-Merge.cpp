/*
Gfg:https://practice.geeksforgeeks.org/problems/account-merge/1
Leetcode:https://leetcode.com/problems/accounts-merge/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void join(vector<int> &parent, int a, int b)
    {
        parent[find(parent, a)] = find(parent, b);
    }
    int find(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> hash;
        sort(accounts.begin(), accounts.end());
        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (!hash.count(email))
                    hash[email] = i;
                else
                    join(parent, i, hash[email]);
            }

        vector<string> mergedMail[n];
        for (auto it : hash)
        {
            string email = it.first;
            int idx = find(parent, it.second);
            mergedMail[idx].push_back(email);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (!mergedMail[i].size())
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
}