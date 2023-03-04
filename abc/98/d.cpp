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

ll digit(ll x)
{
    ll res = 0;
    while (x)
    {
        x /= 2;
        res++;
    }

    return res;
}

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll s = 0;
    ll x = 0;

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && (s + a[j]) == (s ^ a[j]))
        {
            s += a[j];
            j++;
        }

        ans += j - i;

        if (i == j)
        {
            j++;
        }
        else
        {
            s -= a[i];
        }
    }

    cout << ans << endl;
}