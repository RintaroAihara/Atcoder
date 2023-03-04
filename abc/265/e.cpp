#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 998244353;
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

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    ll n, m;
    ll a, b, c, d, e, f;
    cin >> n >> m;
    cin >> a >> b >> c >> d >> e >> f;
    vector<ll> X(m), Y(m);

    for (int i = 0; i < m; i++)
    {
        cin >> X[i] >> Y[i];
    }

    ll ans = 0;

    ans = power(3, n);

    cout << ans << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll x, y, z;
            if (((b - d) * (a * j - X[i]) + (c - a) * (Y[i] - b * j)) % ((c - a) * (f - b) - (b - d) * (e - a)) == 0)
            {
                cout << ((b - d) * (a * j - X[i]) + (c - a) * (Y[i] - b * j)) << endl;
                cout << ((c - a) * (f - b) - (b - d) * (e - a)) << endl;
                z = ((b - d) * (a * j - X[i]) + (c - a) * (Y[i] - b * j)) / ((c - a) * (f - b) - (b - d) * (e - a));
            }
            else
            {
                continue;
            }

            if ((X[i] - (e - a) * z - a * j) % (c - a) == 0)
            {
                cout << (X[i] - (e - a) * z - a * j) << endl;
                cout << c - a << endl;
                y = (X[i] - (e - a) * z - a * j) / (c - a);
            }
            else
            {
                continue;
            }

            x = j - y - z;

            cout << x << y << z << endl;
        }
    }
}