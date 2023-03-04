#include <bits/stdc++.h>

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

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    ll I = a.size(), J = b[0].size(), K = b.size();

    vector<vector<ll>> c(I, vector<ll>(J, 0));
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            for (int k = 0; k < K; k++)
            {
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }

    return c;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> x, ll n)
{
    vector<vector<ll>> y(x.size(), vector<ll>(x.size(), 0));

    for (int i = 0; i < x.size(); i++)
    {
        y[i][i] = 1;
    }

    while (n > 0)
    {
        if (n & 1)
        {
            y = mat_mul(x, y);
        }
        x = mat_mul(x, x);

        n >>= 1;
    }

    return y;
}

int main(void)
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> g(n, vector<ll>(n, 1));
    vector<ll> u(m), v(m);

    map<P, ll> ma;

    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;

        g[u[i]][v[i]] = 0;
        g[v[i]][u[i]] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        g[i][i] = 0;
    }

    auto x = mat_pow(g, k);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << x[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    cout << x[0][0] << endl;

    // vector<ll> d(n, 0);

    // d[0] = 1;

    // for (int i = 0; i < k; i++)
    // {
    //     vector<ll> nd(n, 0);
    // }
}