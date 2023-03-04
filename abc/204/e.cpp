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
        ll c;
        ll d;
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
        q.emplace(0, s);

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

                ll next_d;

                if (-distance[v] - 1 + sqrt(e.d) >= 0)
                {
                    next_d = floor(2 * sqrt(e.d)) + e.c - 1;
                }
                else
                {
                    next_d = distance[v] + e.c + (e.d / (distance[v] + 1));
                }

                if (chmin(distance[e.to], next_d))
                {
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

    Dijkstra D(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;

        D.G[a].push_back({b, c, d});
        D.G[b].push_back({a, c, d});
    }

    ll ans = INF;

    D.dijkstra(0);
    ans = D.distance[n - 1];

    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}