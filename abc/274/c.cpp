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
    vector<ll> a(n + 1);
    vector<ll> k(2 * n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i * 2] = a[i];
        k[i * 2 + 1] = a[i];
    }

    cout << 0 << endl;

    for (int i = 1; i <= 2 * n; i++)
    {
        ll ans = 0;
        ll x = k[i];

        while (x != 1)
        {
            x /= 2;

            ans++;
        }

        cout << ans << endl;
    }
}