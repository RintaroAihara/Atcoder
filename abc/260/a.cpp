#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    string s;
    cin >> s;

    map<char, int> m;

    for (auto &&i : s)
    {
        m[i]++;
    }

    for (auto &&i : m)
    {
        if (i.second == 1)
        {
            cout << i.first << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}