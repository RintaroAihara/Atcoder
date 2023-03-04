#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
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

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(n, 0));

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;

        g[u][v] = 1;
        g[v][u] = 1;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (g[i][j] == 1 && g[j][k] == 1 && g[i][k] == 1)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}