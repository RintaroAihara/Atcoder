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
    ll n, k;
    cin >> n >> k;

    map<ll, ll> m;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        m[a[i]] = i;
    }

    vector<ll> b(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i < k % n)
        {
            b[i] = k / n + 1ll;
        }
        else
        {
            b[i] = k / n;
        }
    }

    vector<ll> ans(n);

    ll x = 0;

    for (auto &&i : m)
    {
        ans[i.second] = b[x];
        x++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}