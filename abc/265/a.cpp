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
    double x, y;

    ll n;
    cin >> x >> y >> n;

    ll ans = 0;

    if (x <= y / 3.0)
    {
        cout << x * n << endl;
    }
    else
    {
        cout << y * int(n / 3) + (n % 3) * x << endl;
    }
}