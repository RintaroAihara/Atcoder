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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

int main(void)
{
    ll n, m;

    cin >> n >> m;

    vector<ll> a(m), b(m);
    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;

        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    ll k;
    cin >> k;

    vector<vector<ll>> g_d(k, vector<ll>(k, INF));
    vector<ll> c(k);

    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        c[i]--;
    }

    for (int i = 0; i < k; i++)
    {
        queue<ll> q;
        q.push(c[i]);

        vector<ll> dis(n, INF);
        dis[c[i]] = 0;

        while (q.size())
        {
            ll p = q.front();
            q.pop();

            for (auto &&x : g[p])
            {
                if (dis[x] == INF)
                {
                    dis[x] = dis[p] + 1;
                    q.push(x);
                }
            }
        }

        for (int j = 0; j < k; j++)
        {
            if (i == j)
            {
                g_d[i][j] = 0;
                g_d[j][i] = 0;
            }

            if (dis[c[j]] == INF)
            {
                cout << -1 << endl;
                return 0;
            }

            ll d;
            d = min(g_d[i][j], dis[c[j]]);

            g_d[i][j] = d;
            g_d[j][i] = d;
        }
    }

    ll maxd = 0;
    bool flag = false;

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            maxd = max(maxd, g_d[i][j]);
        }
    }

    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < k; j++)
    //     {
    //         printf("%lld ", g_d[i][j]);
    //     }
    //     printf("\n");
    // }

    vector<vector<ll>> dp(1 << k, vector<ll>(k, INF));

    for (int i = 0; i < k; i++)
    {
        dp[1 << i][i] = 1;
    }

    for (int bit = 1; bit < 1 << k; bit++)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                dp[bit | 1 << j][j] = min(dp[bit | 1 << j][j], dp[bit][i] + g_d[i][j]);
            }
        }
    }

    ll ans = INF;

    for (int i = 0; i < k; i++)
    {
        ans = min(ans, dp[(1 << k) - 1][i]);
    }

    cout << ans << endl;
}
