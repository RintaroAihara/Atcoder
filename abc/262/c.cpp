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
    vector<ll> a(n);

    ll x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if (i == a[i])
        {
            x++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == a[a[i]])
        {
            y++;
        }
    }

    ll ans = 0;
    ans = x * (x - 1) / 2 + (y - x) / 2;
    cout << ans << endl;
}