/*
GFG: https://practice.geeksforgeeks.org/problems/word-ladder/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        unordered_set<string> word;
        unordered_set<string> vis;
        vis.insert(startWord);
        for (auto st : wordList)
            word.insert(st);

        queue<string> q;
        q.push(startWord);
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop();
                if (curr == targetWord)
                    return level;

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
        return 0;
    }
};
int main()
{
}