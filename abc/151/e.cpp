#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

struct factorial
{
    vector<ll> fac, finv, inv;

    factorial(ll n) : fac(2, 1), finv(2, 1), inv(2, 1)
    {
        for (int i = 2; i <= n; i++)
        {
            fac.push_back(fac[i - 1] * i % MOD);
            inv.push_back(MOD - inv[MOD % i] * (MOD / i) % MOD);
            finv.push_back(finv[i - 1] * inv[i] % MOD);
        }
    }

    ll comb(ll n, ll k)
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

    ll perm(ll n, ll k)
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

int main(void)
{
    ll n, k;
    cin >> n >> k;

    factorial f(n);

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans -= a[i] * f.comb(n - i - 1, k - 1) % MOD;
        ans %= MOD;
        ans += a[i] * f.comb(i, k - 1) % MOD;
        ans %= MOD;
    }

    cout << (ans + MOD) % MOD << endl;
}