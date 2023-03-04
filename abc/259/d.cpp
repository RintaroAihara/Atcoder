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
    ll n;
    ll sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;

    vector<ll> x(n), y(n);
    vector<ll> r(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }

    unionfind u(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll R = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);

            if (R <= (r[i] + r[j]) * (r[i] + r[j]) && R >= (r[i] - r[j]) * (r[i] - r[j]))
            {
                u.unite(i, j);
            }
        }
    }

    set<ll> s, t;

    for (int i = 0; i < n; i++)
    {
        ll R = (x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy);

        if (r[i] * r[i] == R)
        {
            s.insert(u.root(i));
            // cout << u.root(i) << endl;
        }

        R = (x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty);

        if (r[i] * r[i] == R)
        {
            t.insert(u.root(i));
            // cout << u.root(i) << endl;
        }
        // cout << u.root(i) << endl;
    }

    for (auto &&i : s)
    {
        if (t.find(i) != t.end())
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}