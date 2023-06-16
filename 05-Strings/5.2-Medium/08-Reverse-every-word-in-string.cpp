/*
Gfg:https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class gfgSolution
{
public:
    string reverseWords(string S)
    {
        stringstream ss(S);
        string token;
        string ans = "";
        while (getline(ss, token, '.'))
            ans = token + "." + ans;

        ans.pop_back();
        return ans;
    }
};
class leetSolution
{
public:
    string reverseWords(string S)
    {
        stringstream ss(S);
        string token;
        string ans = "";
        while (ss >> token)
            ans = token + " " + ans;

        ans.pop_back();
        return ans;
    }
};
int main()
{
}