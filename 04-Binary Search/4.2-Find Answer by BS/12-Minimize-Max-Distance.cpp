/*
GFG:https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool check(double dis, vector<int> &stations, int k)
    {
        int n = stations.size();
        int new_sta = 0;
        for (int i = 1; i < n; i++)
            new_sta += floor((stations[i] - stations[i - 1]) / dis);
        return new_sta <= k;
    }

public:
    double findSmallestMaxDist(vector<int> &stations, int K)
    {
        int n = stations.size();

        double low = 0, high = stations[n - 1] - stations[0];
        while (high - low > 1e-6)
        {
            double mid = low + (high - low) / 2.0;
            if (check(mid, stations, K))
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};
int main()
{
}