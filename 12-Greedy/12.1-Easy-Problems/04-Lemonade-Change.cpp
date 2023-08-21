/*
Gfg:https://practice.geeksforgeeks.org/problems/lemonade-change/1
Leetcode:https://leetcode.com/problems/lemonade-change/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for(auto bill: bills)
        {
            if (bill == 5)
                five++;
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                ten++, five--;
            }
            else if (bill == 20)
            {
                if (five and ten)
                    five--, ten--;
                else if (five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
int main()
{
}