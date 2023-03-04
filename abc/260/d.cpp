#include <bits/stdc++.h>

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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, vector<ll>> m;
    set<ll> b;
    map<ll, ll> r;

    unionfind u(n);

    for (int i = 0; i < n; i++)
    {
        auto it = b.lower_bound(a[i]);

        if (it == b.end())
        {
            b.insert(a[i]);
            // cout << a[i] << endl;
        }
        else
        {
            u.unite(*it - 1, a[i] - 1);
            b.erase(*it);
            b.insert(a[i]);
        }

        // cout << u.size(a[i] - 1) << endl;

        if (u.size(a[i] - 1) == k)
        {
            // cout << a[i] << endl;
            r[u.root(a[i] - 1)] = i + 1;
            b.erase(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (r[u.root(i)] != 0)
        {
            cout << r[u.root(i)] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}