#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

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

ll comb(ll n, ll k)
{
    ll ans = 1;
    ll i;

    rep(i, 0, k)
    {
        ans *= n - i;
        ans %= MOD;
        ans *= power(i + 1, MOD - 2);
        ans %= MOD;
    }

    return ans;
}

int main(void)
{
    ll n, a, b;
    ll ans = 0;

    cin >> n >> a >> b;

    ans = power(2, n);

    ans = (ans - comb(n, a) - comb(n, b) - 1 + MOD * 2) % MOD;

    cout << ans << endl;
}