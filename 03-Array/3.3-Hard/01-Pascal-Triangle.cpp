/*
Link:https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1
*/
#include <bits/stdc++.h>
#define ll long long;
using namespace std;
class var1Solution
{
public:
    int ncr(int n, int r)
    {
        int res = 1;
        for (int i = 0; i < r; i++)
        {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }
    int pascalTriangle(int r, int c)
    {
        return ncr(r - 1, c - 1);
    }
};
class var2Solution
{
public:
    ll mod = 1e9 + 7;
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        vector<ll> ans;
        ans.push_back(1);
        long long temp = 1;
        for (int i = 1; i < n; i++)
        {
            temp = ((temp * (n - i))) / i;
            ans.push_back(temp % mod);
        }
        return ans;
    }
};
class var3Solution
{
public:
    ll mod = 1e9 + 7;
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        // code here
        if (!n)
            return {};
        vector<vector<long long int>> ans;
        ans.push_back({1});

        for (int i = 1; i < n; i++)
        {
            vector<long long int> temp;
            temp.push_back(1);
            for (int j = 0; j < ans[i - 1].size() - 1; j++)
                temp.push_back((ans[i - 1][j] + ans[i - 1][j + 1]) % mod);
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans[n - 1];
    }

    long long int mod = 1e9 + 7;
    vector<ll> nthRowOfPascalTriangle(int n)
    {
        if (n == 1)
            return {1};

        vector<ll> ans;
        vector<ll> v = nthRowOfPascalTriangle(n - 1);

        ans.push_back(1);

        for (int i = 1; i < n - 1; i++)
            ans.push_back((v[i - 1] + v[i]) % mod);

        ans.push_back(1);

        return ans;
    }
};
int main()
{
}