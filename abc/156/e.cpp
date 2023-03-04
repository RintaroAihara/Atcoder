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

int main(void)
{
    int n, k;
    int i;
    ll ans = 0;

    cin >> n >> k;

    factorial f(n);

    rep(i, 0, min(k + 1, n))
    {
        ans += f.comb(n, i) * f.comb(n - 1, n - i - 1);
        ans %= MOD;
    }

    cout << ans << endl;
}