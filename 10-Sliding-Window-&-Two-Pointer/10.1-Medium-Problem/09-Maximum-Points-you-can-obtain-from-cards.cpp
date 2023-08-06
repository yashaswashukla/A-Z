/*
Gfg:https://practice.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1
Leetcode:https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int currSum = 0, ans = 0;
        for (int i = 0; i < k; i++)
            currSum += cardPoints[i];
        ans = currSum;

        for (int i = k - 1; i >= 0; i--)
        {
            currSum -= cardPoints[i];
            currSum += cardPoints[n - k + i];
            ans = max(ans, currSum);
        }
        return ans;
    }
};
int main()
{
}