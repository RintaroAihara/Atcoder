#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <numeric>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    map<P, ll> m;
    ll zero = 0, az = 0, bz = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];

        if (a[i] == 0 && b[i] == 0)
        {
            zero++;
            continue;
        }
        else if (a[i] == 0 && b[i] != 0)
        {
            az++;
            continue;
        }
        else if (b[i] == 0 && a[i] != 0)
        {
            bz++;
            continue;
        }

        ll g = gcd(a[i], b[i]);
        if (b[i] < 0)
        {
            m[{-a[i] / g, -b[i] / g}]++;
        }
        else
        {
            m[{a[i] / g, b[i] / g}]++;
        }
    }

    ll ans = 1;

    for (auto &&i : m)
    {
        ll x = i.first.first, y = i.first.second;
        ll u = i.second, v;
        i.second = 0;

        if (u == 0)
        {
            continue;
        }

        if (x <= 0)
        {
            v = m[{y, -x}];
            m[{y, -x}] = 0;
        }
        else
        {
            v = m[{-y, x}];
            m[{-y, x}] = 0;
        }

        // cout << u << " " << v << endl;

        ans *= (power(2, u) + power(2, v) - 1) % MOD;
        ans %= MOD;
    }

    ans *= (power(2, az) + power(2, bz) - 1) % MOD;
    ans %= MOD;

    cout << (ans - 1 + zero + MOD) % MOD << endl;
}
