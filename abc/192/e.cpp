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
        ll k;
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
        int i;
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

                if (distance[e.to] > (distance[v] + e.k - 1) / e.k * e.k + e.cost)
                {
                    distance[e.to] = (distance[v] + e.k - 1) / e.k * e.k + e.cost;
                    q.push(P(distance[e.to], e.to));
                }
            }
        }
    }
};

int main(void)
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;

    Dijkstra d(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;

        d.G[a].push_back({b, t, k});
        d.G[b].push_back({a, t, k});
    }

    d.dijkstra(x);

    if (d.distance[y] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d.distance[y] << endl;
    }
}