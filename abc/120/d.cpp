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

struct unionfind
{
    vector<ll> d;

    unionfind(ll n) : d(n, -1) {}

    ll root(ll x)
    {
        if (d[x] < 0)
        {
            return x;
        }
        else
        {
            return d[x] = root(d[x]);
        }
    }

    bool unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
        {
            return false;
        }

        if (d[x] > d[y])
        {
            swap(x, y);
        }

        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    ll size(ll x)
    {
        return -d[root(x)];
    }
};

int main(void)
{
    ll n, m;

    cin >> n >> m;

    unionfind u(n + 1);
    stack<P> s;
    set<ll> t;
    vector<ll> ans(m, 0);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;

        cin >> a >> b;

        a--;
        b--;

        s.push(P(a, b));
    }

    ll res = 0;

    ans[m - 1] = (n * n - n) / 2;

    for (ll i = 1; i < m; i++)
    {
        P p = s.top();
        s.pop();

        if (u.same(p.first, p.second))
        {
            ans[m - i - 1] = ans[m - i];
        }
        else
        {
            ans[m - i - 1] = ans[m - i] - u.size(p.first) * u.size(p.second);
        }

        u.unite(p.first, p.second);
    }

    for (auto a : ans)
    {
        cout << a << endl;
    }
}
