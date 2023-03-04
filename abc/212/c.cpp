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
    ll n, m;
    cin >> n >> m;

    ll l, r;

    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    ll ans = INF;

    for (int i = 0; i < n; i++)
    {
        auto x = lower_bound(b.begin(), b.end(), a[i]);

        if (x == b.end())
        {
            x--;
            chmin(ans, abs(a[i] - *x));
        }
        else if (x == b.begin())
        {
            chmin(ans, abs(a[i] - *x));
        }
        else
        {
            chmin(ans, abs(a[i] - *x));
            x--;
            chmin(ans, abs(a[i] - *x));
        }
    }

    cout << ans << endl;
}