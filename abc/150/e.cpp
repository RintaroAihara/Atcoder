#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

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
    int N;
    vector<ll> C;
    int i, j;
    int n;
    ll csum = 0;
    ll ans = 0;

    cin >> N;

    C.resize(N);

    rep(i, 0, N)
    {
        cin >> C[i];
    }

    factorial f(N);

    sort(C.begin(), C.end());

    // rep(i, 1, N + 1)
    // {
    rep(j, 0, N)
    {

        // n = (i * f.comb(N - 1, i - 1) - j * f.comb(N - 2, i - 2)) % MOD;
        n = ((N - 1) * power(2, N - 2) + power(2, N - 1) - j * power(2, N - 1)) % MOD;

        ans += C[j] * n % MOD;
        ans %= MOD;
    }
    // }

    ans *= power(2, N);
    ans %= MOD;
    cout << ans << endl;
}