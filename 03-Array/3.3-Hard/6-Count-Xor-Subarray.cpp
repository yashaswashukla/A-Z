/*
Gfg:https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class naiveSolution
{
private:
    int count = 0;
    void helper(vector<int> &arr, int ind, int k, int curxor)
    {
        if (curxor == k)
            count++;

        for (int i = ind; i < arr.size(); i++)
            helper(arr, i + 1, k, curxor ^ arr[i]);
    }

public:
    int subsetXOR(vector<int> arr, int N, int K)
    {
        helper(arr, 0, K, 0);
        return count;
    }
};
class dpSolution
{
};
int main()
{
}