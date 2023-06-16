/*
Link:https://leetcode.com/problems/majority-element-ii/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> majorityElement(vector<int> &nums)
    {
        int cand1 = -1, cand2 = -1, vote1 = 0, vote2 = 0;

        for (auto cand : nums)
        {
            if (vote1 == 0 and cand2 != cand)
            {
                cand1 = cand;
                vote1++;
            }
            else if (vote2 == 0 and cand1 != cand)
            {
                cand2 = cand;
                vote2++;
            }
            else if (cand == cand1)
                vote1++;
            else if (cand == cand2)
                vote2++;
            else
                vote1--, vote2--;
        }

        vote1 = 0, vote2 = 0;
        for (auto cand : nums)
        {
            if (cand == cand1)
                vote1++;
            else if (cand == cand2)
                vote2++;
        }

        vector<int> ans;
        if (vote1 > nums.size() / 3)
            ans.push_back(cand1);

        if (vote2 > nums.size() / 3)
            ans.push_back(cand2);
        return ans;
    }
};
int main()
{
}