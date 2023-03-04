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
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    ll ans = k;
    vector<ll> d(n, INF);
    d[0] = 0;
    queue<ll> q;
    q.emplace(0);

    while (q.size())
    {
        ll p = q.front();
        q.pop();

        ll c = k - min(d[p] + 1, 2ll);

        for (ll i = 0; i < g[p].size(); i++)
        {
            if (d[g[p][i]] < d[p])
            {
                c++;
                continue;
            }

            ans *= c - i;
            ans %= MOD;

            if (chmin(d[g[p][i]], d[p] + 1))
            {
                q.emplace(g[p][i]);
            }
        }
    }

    cout << ans << endl;
}