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

class unionfind
{
private:
    vector<long long> d;

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

    bool same(long long x, long long y)
    {
        return root(x) == root(y);
    }

    long long size(long long x)
    {
        return -d[root(x)];
    }
};

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n), x(m), y(m);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    unionfind u(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;

        u.unite(x[i], y[i]);
    }

    map<int, set<int>> ma;

    for (int i = 0; i < n; i++)
    {
        ma[u.root(i)].insert(i);
    }

    ll ans = 0;

    for (auto &&i : ma)
    {
        for (auto &&j : i.second)
        {
            if (i.second.find(p[j]) != i.second.end())
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
