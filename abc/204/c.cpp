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
        ll a, b;
        cin >> a >> b;

        a--, b--;

        g[a].push_back(b);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        queue<ll> q;
        q.push(i);
        vector<bool> d(n, false);
        d[i] = true;
        ans++;

        while (q.size())
        {
            ll x = q.front();
            q.pop();

            for (auto &&i : g[x])
            {
                if (d[i])
                {
                    continue;
                }

                d[i] = true;
                q.push(i);
                ans++;
            }
        }
    }

    cout << ans << endl;
}