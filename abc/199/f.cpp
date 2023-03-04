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
        g[b].push_back(a);
    }

    vector<bool> seen(n, false);

    ll ans = 1;

    vector<ll> v;
    vector<ll> o(n, 3);

    for (int i = 0; i < n; i++)
    {
        if (seen[i])
        {
            continue;
        }
        queue<ll> q;
        ll tmp = 1;
        
        q.push(i);

        while (q.size())
        {
            ll p = q.front();
            q.pop();

            seen[p] = true;
            tmp *= max(o[p], 0ll);

            for (auto &&j : g[p])
            {
                if (seen[j])
                {
                    continue;
                }

                o[j]--;
                q.push(j);
            }
        }

        v.push_back(tmp);
    }

    for (auto &&i : v)
    {
        ans *= i;
    }

    cout << ans << endl;
}