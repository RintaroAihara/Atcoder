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
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

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
    int n, m;

    cin >> n >> m;

    unionfind uf(n);

    set<int> ans;

    for (int i = 0; i < m; i++)
    {
        int x, y,z;

        cin >> x >> y>>z;

        x--;
        y--;

        uf.unite(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        ans.insert(uf.root(i));
    }

    cout << ans.size() << endl;
}