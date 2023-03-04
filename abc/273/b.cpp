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
    ll x, k;
    cin >> x >> k;

    for (int i = 0; i < k; i++)
    {
        ll t = 1;
        for (int j = 0; j < i; j++)
        {
            t *= 10;
        }

        ll d = (x / t) % 10;

        if (d < 5)
        {
            x -= x % (t * 10);
        }
        else
        {
            x += t * 10;
            x -= x % (t * 10);
        }
    }

    cout << x << endl;
}