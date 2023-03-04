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

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main(void)
{
    ll l, r;
    cin >> l >> r;

    ll ans = 0;

    ll c = 0;

    vector<vector<ll>> s(110, vector<ll>(110, 0));

    for (ll i = 2; i <= r; i++)
    {
        ll ri = (r / i);
        ll li = (l + i - 1ll) / i;

        if (li == ri)
        {
            break;
        }

        for (ll j = max(2ll, li); j < ri; j++)
        {
            vector<ll> d = divisor(j);

            
            ans += ri - j;
            ans -= ri / j - 1ll;
        }
    }

    cout << ans * 2ll << endl;
    cout << c * 2 << endl;
}