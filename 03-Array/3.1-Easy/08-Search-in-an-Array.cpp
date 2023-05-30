/*
GFG:https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1
Leetcode:
*/
#include <bits/stdc++.h>
using namespace std;
class linearSolution
{
    int searchInSorted(int arr[], int N, int K)
    {
        for (int i = 0; i < N; i++)
            if (arr[i] == K)
                return i;
        return -1;
    }
};
class binarySolution
{
    int searchInSorted(int arr[], int N, int K)
    {
        int low = 0, high = N - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == K)
                return 1;
            if (arr[mid] < K)
                low = mid + 1;
            else if (arr[mid] > K)
                high = mid - 1;
        }
        return -1;
    }
};
int main()
{
}