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
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        ll b;
        cin >> b;
        auto x = lower_bound(a.begin(), a.end(), b) - a.begin();

        ll y = x - 1;

        ll ans = INF;

        if (x >= n)
        {
            ans = abs(a[y] - b);
        }
        else
        {
            ans = min(abs(a[x] - b), abs(a[y] - b));
        }

        if (y < 0)
        {
            ans = abs(a[x] - b);
        }
        else
        {
            ans = min(abs(a[x] - b), abs(a[y] - b));
        }

        cout << ans << endl;
    }
}