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

    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        m[a]++;
    }

    ll ans = n * (n - 1) / 2;

    for (auto &&i : m)
    {
        ans -= (i.second) * (i.second - 1) / 2;
    }

    cout << ans << endl;
}