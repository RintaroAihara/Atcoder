#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
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
    int x, y;
    int i, j;
    int a, b;
    int ans;
    factorial f(1000010);

    cin >> x >> y;

    if ((x + y) % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    a = (2 * y - x) / 3;
    b = (2 * x - y) / 3;

    cout << f.comb(a + b, a) << endl;
}