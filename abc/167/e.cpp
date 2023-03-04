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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 998244353;
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

class factorial
{
private:
    vector<ll> fac, finv, inv;

public:
    factorial(ll n) : fac(2, 1), finv(2, 1), inv(2, 1)
    {
        for (ll i = 2; i <= n; i++)
        {
            fac.push_back(fac[i - 1] * i % MOD);
            inv.push_back(MOD - inv[MOD % i] * (MOD / i) % MOD);
            finv.push_back(finv[i - 1] * inv[i] % MOD);
        }
    }

    ll comb(ll n, ll k)
    {
        if (n < k || n < 0 || k < 0)
        {
            return 0;
        }

        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    ll perm(ll n, ll k)
    {
        if (n < k || n < 0 || k < 0)
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
    ll n, m, k;
    cin >> n >> m >> k;

    factorial f(n);

    ll ans = 0;

    for (int i = 0; i <= k; i++)
    {
        ans += (f.comb(n - 1, i) * power(m - 1, n - i - 1) % MOD) * m % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}