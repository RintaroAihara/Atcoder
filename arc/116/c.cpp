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

class eratosthenes_sieve
{
private:
    int n;
    vector<int> f;

public:
    vector<int> primes;

    eratosthenes_sieve(int n) : f(n + 1)
    {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; i++)
        {
            if (!f[i])
            {
                f[i] = i;
                primes.emplace_back(i);
                for (ll j = i * i; j <= n; j += i)
                {
                    if (!f[j])
                    {
                        f[j] = i;
                    }
                }
            }
        }
    }

    map<ll, ll> prime_factor(int x)
    {
        map<ll, ll> res;

        while (x != 1)
        {
            res[f[x]]++;
            x /= f[x];
        }

        return res;
    }
};

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

int main(void)
{
    ll n, m;
    cin >> n >> m;

    eratosthenes_sieve e(m);
    factorial f(400000);

    ll ans = 0;

    for (ll i = 1; i <= m; i++)
    {
        ll tmp = 1;

        for (auto &&j : e.prime_factor(i))
        {
            tmp *= f.comb(n - 1 + j.second, n - 1) % MOD;
            tmp %= MOD;
        }

        ans += tmp % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}