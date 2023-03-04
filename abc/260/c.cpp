#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e17 + 7;
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

ll N, X, Y;
ll ans = 0;
ll red(ll, ll);
ll blue(ll, ll);

vector<ll> v(100, -INF);

ll red(ll n, ll x)
{
    if (n == 1)
    {
        return 0;
    }
    else if (v[n] != -INF)
    {
        return v[n] * x;
    }

    v[n] = red(n - 1, x) + blue(n, x * X);
    return v[n];
}

ll blue(ll n, ll x)
{
    if (n == 1)
    {
        return x;
    }

    return red(n - 1, x) + blue(n - 1, x * Y);
}

int main(void)
{
    cin >> N >> X >> Y;

    cout << red(N, 1) << endl;
}