 /*
Gfg:
Leetcode:https://leetcode.com/problems/word-break/description/
*/
#include <bits/stdc++.h>
using namespace std;
class bruteRecSolution
{
public:
    bool helper(string &s, int idx, unordered_set<string> &hash)
    {
        if (idx == (int)s.length())
            return true;

        for (int i = idx; i < (int)s.length(); i++)
        {
            string pre = s.substr(idx, i - idx + 1);
            if (hash.count(pre) and helper(s, i + 1, hash))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> hash;
        for (auto s : wordDict)
            hash.insert(s);
        return helper(s, 0, hash);
    }
};
class bruteMemoSolution
{
public:
    bool helper(string &s, int idx, unordered_set<string> &hash, vector<int> &dp)
    {
        if (idx == (int)s.length())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = idx; i < (int)s.length(); i++)
        {
            string pre = s.substr(idx, i - idx + 1);
            if (hash.count(pre) and helper(s, i + 1, hash, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp((int)s.length(), -1);
        unordered_set<string> hash;
        for (auto s : wordDict)
            hash.insert(s);
        return helper(s, 0, hash, dp);
    }
};
int main()
{
}