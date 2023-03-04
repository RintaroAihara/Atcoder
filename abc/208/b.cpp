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
    ll p;
    cin >> p;

    vector<ll> a(15, 0);

    ll x = 1;

    for (ll i = 1; i < 15; i++)
    {
        x *= i;
        a[i] = x;
    }

    ll ans = 0;

    for (int i = 10; i >= 1; i--)
    {
        ans += p / a[i];
        p %= a[i];
    }

    cout << ans << endl;
}
