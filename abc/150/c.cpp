#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

struct factorial
{
    vector<ll> fac, finv, inv;

    factorial(int n)
    {
        int i;

        rep(i, 0, 1)
        {
            fac.push_back(1);
            finv.push_back(1);
            inv.push_back(1);
        }

        rep(i, 2, n)
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
    int N;
    vector<P> v;
    int p, q;
    int i, j;
    bool flag_p, flag_q;
    int pp = 0, qp = 0;

    cin >> N;

    factorial f(N);

    v.resize(N);

    rep(i, 0, N - 1)
    {
        v[i].first = i + 1;
        v[i].second = i + 1;
    }

    rep(i, 0, N - 1)
    {
        cin >> p;
        pp += f.fac[N - 1 - i] * (v[p - 1].second - 1);
        rep(j, p, N - 1)
        {
            v[j].second--;
        }
    }

    rep(i, 0, N - 1)
    {
        v[i].first = i + 1;
        v[i].second = i + 1;
    }

    rep(i, 0, N - 1)
    {
        cin >> q;
        qp += f.fac[N - 1 - i] * (v[q - 1].second - 1);
        rep(j, q, N - 1)
        {
            v[j].second--;
        }
    }
    cout << abs(pp - qp) << endl;
}