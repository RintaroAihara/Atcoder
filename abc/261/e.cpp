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
    ll n, c;
    cin >> n >> c;
    vector<ll> x(40, 0);
    vector<vector<ll>> b(40, vector<ll>(2, 0));
    for (int i = 0; i < 40; i++)
    {
        b[i][1] = 1;
    }

    ll i = 0;
    while (c)
    {
        x[i] = c % 2;
        i++;
        c /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        ll t, a;
        cin >> t >> a;

        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 33; j++)
            {
                if (t == 1)
                {
                    b[j][k] &= ((a >> j) & 1);
                }
                else if (t == 2)
                {
                    b[j][k] |= ((a >> j) & 1);
                }
                else if (t == 3)
                {
                    b[j][k] ^= ((a >> j) & 1);
                }
            }
        }

        ll ans = 0;
        ll z = 1;

        for (int j = 0; j < 33; j++)
        {
            ans += z * b[j][x[j]];
            x[j] = b[j][x[j]];
            z *= 2ll;
        }
        cout << ans << endl;
    }
}