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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n - 1);
    map<ll, ll> ma;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        ma[x] = y;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (t <= a[i])
        {
            cout << "No" << endl;
            return 0;
        }

        t -= a[i];
        t += ma[i + 2];
    }
    cout << "Yes" << endl;
}