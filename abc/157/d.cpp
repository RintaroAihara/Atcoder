#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

struct unionfind
{
    vector<int> d;

    unionfind(int n) : d(n, -1) {}

    int root(int x)
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

    bool unite(int x, int y)
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

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    int size(int x)
    {
        return -d[root(x)];
    }
};

int main(void)
{
    int n, m, k;
    int a, b, c, d;
    int i, j;
    vector<int> fr(100010, 0);
    vector<int> bl[100010];

    cin >> n >> m >> k;

    unionfind uf(n);

    rep(i, 0, m)
    {
        cin >> a >> b;

        a--;
        b--;

        fr[a]++;
        fr[b]++;
        uf.unite(a, b);
    }

    rep(i, 0, k)
    {
        cin >> c >> d;

        c--;
        d--;

        bl[c].push_back(d);
        bl[d].push_back(c);
    }

    rep(i, 0, n)
    {
        int ans = uf.size(i) - 1 - fr[i];

        for (auto &x : bl[i])
        {
            if (uf.same(i, x))
            {
                ans--;
            }
        }

        printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
    }
}