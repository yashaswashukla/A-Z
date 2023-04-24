/*
GFG:
    Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class naiveSolution // Use the merge method of merge sort
{
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
    }
};
class betterSolution
{
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        // Your code goes here
    }
};
class optimalSolution
{
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        int n1 = array1.size();
        int n2 = array2.size();
        if (n1 > n2)
            return MedianOfArrays(array2, array1);
        int left = 0, right = n1;

        while (left <= right)
        {
            int cut1 = left + (right - left) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : array1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : array2[cut2 - 1];

            int right1 = (cut1 == n1) ? INT_MAX : array1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : array2[cut2];

            if (left1 <= right2 and left2 <= right1)
            {
                if ((n1 + n2) % 2)
                    return max(left1, left2);
                else
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            else if (left1 > right2)
                right = cut1 - 1;
            else
                left = cut1 + 1;
        }
        return 0;
    }
};
int main()
{
}