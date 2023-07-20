/*
GFG:https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> temp;
    int level = 1;
    void dfs(int curlevel, string curr, string endWord, unordered_set<string> &word, unordered_set<string> &vis)
    {
        if (curlevel > level)
            return;
        vis.insert(curr);
        temp.push_back(curr);
        if (curr == endWord)
            ans.push_back(temp);

        for (int i = 0; i < (int)curr.length(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                char ch = curr[i];
                curr[i] = 'a' + j;
                if (word.find(curr) != word.end() and vis.find(curr) == vis.end())
                    dfs(curr, endWord, word, vis);

                curr[i] = ch;
            }
        }
        temp.pop_back();
    }

public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // Code here
        unordered_set<string> word;
        unordered_set<string> vis;
        vis.insert(beginWord);
        for (auto st : wordList)
            word.insert(st);

        queue<string> q;
        q.push(beginWord);

        bool found = false;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                {
                    found = true;
                    break;
                }

                for (int i = 0; i < (int)curr.length(); i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        char ch = curr[i];
                        curr[i] = 'a' + j;
                        if (word.find(curr) != word.end() and vis.find(curr) == vis.end())
                        {
                            vis.insert(curr);
                            q.push(curr);
                        }
                        curr[i] = ch;
                    }
                }
            }
            level++;
        }
        vis.clear();
        if (found)
            dfs(0, beginWord, endWord, word, vis);
        else
            return {};
    }
};
int main()
{
}