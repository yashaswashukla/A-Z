/*
 */
#include <bits/stdc++.h>
using namespace std;
class comp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> hash;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash[arr[i]]++;
    }
    for (auto it = hash.begin(); it != hash.end(); it++)
        pq.push({it->second, it->first});

    while (!pq.empty())
    {
        auto temp = pq.top();
        while (temp.first--)
            cout << temp.second << " ";
        pq.pop();
    }
    cout << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}