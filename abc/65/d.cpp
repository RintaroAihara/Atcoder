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

int main(void)
{
    ll n;
    cin >> n;

    vector<P> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        x[i] = {a, i};
        y[i] = {b, i};
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    using PP = pair<ll, P>;

    priority_queue<PP, vector<PP>, greater<PP>> q;

    for (int i = 0; i < n - 1; i++)
    {
        q.push({x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second}});
        q.push({y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second}});
    }

    ll ans = 0;

    unionfind u(n);

    while (q.size())
    {
        PP p = q.top();
        q.pop();

        if (u.unite(p.second.first, p.second.second))
        {
            ans += p.first;
        }
    }

    cout << ans << endl;
}