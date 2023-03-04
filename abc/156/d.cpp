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

struct factorial
{
    vector<ll> fac, finv, inv;

    factorial(int n) : fac(2, 1), finv(2, 1), inv(2, 1)
    {
        int i;

        rep(i, 2, n + 1)
        {
            fac.push_back(fac[i - 1] * i % MOD);
            inv.push_back(MOD - inv[MOD % i] * (MOD / i) % MOD);
            finv.push_back(finv[i - 1] * inv[i] % MOD);
        }
    }

    ll comb(int n, int k)
    {
        if (n < k)
        {
            return 0;
        }

        if (n < 0 || k < 0)
        {
            return 0;
        }

        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    ll perm(int n, int k)
    {
        if (n < k)
        {
            return 0;
        }

        if (n < 0 || k < 0)
        {
            return 0;
        }

        return fac[n] * finv[n - k] % MOD;
    }
};

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
    ll n, a, b;
    ll i;
    ll ans = 0;
    ll comba = 1, combb = 1;

    cin >> n >> a >> b;

    factorial f(max(a, b));

    rep(i, 0, a)
    {
        comba *= n - i;
        comba %= MOD;
        comba *= f.inv[i + 1];
        comba %= MOD;
    }

    rep(i, 0, b)
    {
        combb *= n - i;
        combb %= MOD;
        combb *= f.inv[i + 1];
        combb %= MOD;
    }

    ans = power(2, n);

    ans = (ans - comba - combb - 1 + MOD * 3) % MOD;

    cout << ans << endl;
}