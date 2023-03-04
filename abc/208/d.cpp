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

class Dijkstra
{
private:
    ll n; //頂点数

    struct edge
    {
        ll to;
        ll cost;
    };

public:
    vector<vector<edge>> G; //隣接リスト
    vector<ll> distance;

    Dijkstra(ll n) : n(n)
    {
        G.assign(n, vector<edge>());
    }

    void dijkstra(int s, int k)
    {
        priority_queue<P, vector<P>, greater<P>> q;
        distance.assign(n, INF);
        distance[s] = 0;
        q.emplace(0, s);

        while (q.size())
        {
            P p = q.top();
            q.pop();
            int v = p.second;

            if (v > k && v != s)
            {
                continue;
            }

            if (distance[v] < p.first)
            {
                continue;
            }

            for (auto &x : G[v])
            {
                edge e = x;

                if (distance[e.to] > distance[v] + e.cost)
                {
                    distance[e.to] = distance[v] + e.cost;
                    q.emplace(distance[e.to], e.to);
                }
            }
        }
    }
};

int main(void)
{
    ll n, m;
    cin >> n >> m;
    Dijkstra d(n);

    vector<vector<ll>> g(n, vector<ll>(n, INF)), G(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++)
    {
        g[i][i] = 0;
    }

    ll ans = 0;

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        a--, b--;
        chmin(g[a][b], c);
    }

    ll TMP = ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                chmin(g[j][k], g[j][i] + g[i][k]);

                if (g[j][k] == INF)
                {
                    continue;
                }

                ans += g[j][k];
            }
        }
    }

    cout << ans << endl;
}