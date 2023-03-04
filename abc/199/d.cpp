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

class unionfind
{
private:
    vector<long long> d;

    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

public:
    unionfind(long long n) : d(n, -1) {}

    long long root(long long x)
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

    bool unite(long long x, long long y)
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

    long long size(long long x)
    {
        return -d[root(x)];
    }
};

vector<vector<ll>> g;
ll tmp;
ll l, p;
vector<ll> v;

void dfs(vector<ll> rgb)
{
    if (l == rgb.size())
    {
        bool f = true;

        for (auto &&i : rgb)
        {
            cout << i;
        }

        cout << endl;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if (g[v[i]][v[j]] == 1)
                {
                    if (rgb[i] == rgb[j])
                    {
                        cout << 'c' << endl;
                        f = false;
                        break;
                    }
                }
            }
        }

        if (f)
        {
            tmp++;
        }

        return;
    }

    for (int i = 0; i < 2; i++)
    {
        vector<ll> x = rgb;
        x.push_back((*rgb.rbegin() + i + 1) % 3);
        dfs(x);
    }
}

int main(void)
{
    ll n, m;
    cin >> n >> m;

    g.assign(n, vector<ll>(n, 0));

    unionfind u(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = 1;
        g[b][a] = 1;

        u.unite(a, b);
    }

    vector<vector<ll>> s(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        s[u.root(i)].push_back(i);
    }

    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        tmp = 0;

        if (s[i].size())
        {
            l = s[i].size();
            v = s[i];
            dfs({0});
            dfs({1});
            dfs({2});

            ans *= tmp;
        }
    }

    cout << ans << endl;
}