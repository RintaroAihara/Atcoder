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
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        ll l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            ll x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll s, t;
        cin >> s >> t;
        cout << v[s - 1][t - 1] << endl;
    }
}