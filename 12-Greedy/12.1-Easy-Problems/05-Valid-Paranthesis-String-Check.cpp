/*
Leetcode:https://leetcode.com/problems/valid-parenthesis-string/
*/
#include <bits/stdc++.h>
using namespace std;
class leetSolution
{
public:
    bool checkValidString(string s)
    {
        int minCount = 0, maxCount = 0;
        for (auto ch : s)
        {
            if (ch == '(')
                minCount++, maxCount++;
            else if (ch == ')')
                minCount--, maxCount--;
            else
                minCount--, maxCount++;

            if (maxCount < 0)
                return false;
            minCount = max(0, minCount);
        }
        return minCount == 0;
    }
};
int main()
{
}