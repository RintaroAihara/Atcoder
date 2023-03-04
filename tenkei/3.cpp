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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<ll> q;
    q.push(0);

    vector<ll> d(n, INF);
    d[0] = 0;

    ll lx;

    while (q.size())
    {
        ll x = q.front();
        q.pop();
        lx = x;

        for (auto &&i : g[x])
        {
            if (d[i] != INF)
            {
                continue;
            }

            chmin(d[i], d[x] + 1);

            q.push(i);
        }
    }


    q.push(lx);
    d.assign(n, INF);
    d[lx] = 0;

    while (q.size())
    {
        ll x = q.front();
        q.pop();
        lx = x;

        for (auto &&i : g[x])
        {
            if (d[i] != INF)
            {
                continue;
            }

            chmin(d[i], d[x] + 1);

            q.push(i);
        }
    }

    cout << d[lx] + 1 << endl;
}
