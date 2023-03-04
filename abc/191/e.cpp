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

    void dijkstra(int s)
    {
        priority_queue<P, vector<P>, greater<P>> q;
        distance.assign(n, INF);
        distance[s] = 0;
        q.push(P(0, s));

        while (q.size())
        {
            P p = q.top();
            q.pop();
            int v = p.second;

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
                    q.push(P(distance[e.to], e.to));
                }
            }
        }
    }
};

int main(void)
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll>(n, INF));
    Dijkstra d(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        d.G[a].push_back({b, c});
        g[a][b] = min(g[a][b], c);
    }

    for (int i = 0; i < n; i++)
    {
        d.dijkstra(i);

        ll ans = INF;

        for (int j = 0; j < n; j++)
        {
            ll tmp;

            tmp = g[j][i] + d.distance[j];

            ans = min(tmp, ans);
        }

        if (ans == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
