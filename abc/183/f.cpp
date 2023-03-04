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

vector<map<ll, ll>> m;

struct unionfind
{
    vector<long long> d;

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

        for (auto &&i : m[y])
        {
            m[x][i.first] += m[y][i.first];
        }

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
    ll n, q;
    cin >> n >> q;

    unionfind u(n);
    vector<int> c(n);

    m.assign(n, map<ll, ll>());

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        m[i][c[i]]++;
    }

    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;

        if (p == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            u.unite(a, b);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;

            cout << m[u.root(x)][y] << endl;
        }
    }
}
