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

ll r, c;

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

                if (distance[e.to] > distance[v] + e.cost)
                {
                    cout << v << " " << e.to << endl;
                    distance[e.to] = distance[v] + e.cost;
                    q.emplace(distance[e.to], e.to);
                }
            }
        }
    }
};

int main(void)
{
    cin >> r >> c;

    Dijkstra d(r * c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            ll cost;
            cin >> cost;

            d.G[c * i + j].push_back({c * i + j + 1, cost});
        }
    }

    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ll cost;
            cin >> cost;

            d.G[c * i + j].push_back({c * (i + 1) + j, cost});
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            d.G[c * i + j].push_back({c * (i - 1) + j, 1});
        }
    }

    d.dijkstra(0);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%2lld ", d.distance[c * i + j]);
        }
        printf("\n");
    }

    cout << d.distance[r * c - 1] << endl;
}