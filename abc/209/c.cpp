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
    vector<ll> c(n);

    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++)
    {
        ans *= (c[i] - i);
        ans %= MOD;
    }

    cout << ans << endl;
}