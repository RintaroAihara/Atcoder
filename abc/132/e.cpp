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

int main(void)
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    ll s, t;
    cin >> s >> t;
    s--, t--;

    vector<vector<ll>> d(n, vector<ll>(3, INF));

    d[s][0] = 0;
    queue<ll> q;
    q.push(s);

    while (q.size())
    {
        ll p = q.front();
        q.pop();

        for (auto &&i : g[p])
        {
            bool flag = false;
            for (int j = 0; j < 3; j++)
            {
                ll x;
                x = d[p][j] + 1;

                if (d[i][x % 3] > x)
                {
                    flag = true;
                    d[i][x % 3] = x;
                    q.push(i);
                }
            }
        }
    }

    if (d[t][0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[t][0] / 3 << endl;
    }
}