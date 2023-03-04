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
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> s;
    map<ll, ll> c;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        c[a[i]]++;
    }

    map<ll, ll> m;
    ll x = 1;
    for (auto &&i : s)
    {
        m[i] = s.size() - x;
        x++;
    }

    vector<ll> k(n, 0);

    for (auto &&i : m)
    {
        k[i.second] += c[i.first];
    }

    for (int i = 0; i < n; i++)
    {
        cout << k[i] << endl;
    }
}