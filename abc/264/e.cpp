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
    ll n, m, e;
    cin >> n >> m >> e;

    vector<ll> u(e), v(e);

    for (int i = 0; i < e; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }

    ll q;
    cin >> q;
    vector<ll> x(q);

    set<ll> X;

    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
        x[i]--;
        X.insert(x[i]);
    }

    unionfind uf(n + m);

    for (int i = 0; i < e; i++)
    {
        if (X.find(i) != X.end())
        {
            continue;
        }

        uf.unite(u[i], v[i]);
    }

    ll ans = 0;
    map<ll, ll> c;
    vector<ll> did(n + m + 10, false);

    for (int i = 0; i < n; i++)
    {
        c[uf.root(i)]++;
    }

    for (int i = n; i < n + m; i++)
    {
        ll r = uf.root(i);
        if (did[r])
        {
            continue;
        }

        ans += c[r];
        did[r] = true;
    }

    vector<ll> res;
    res.push_back(ans);

    for (int i = q - 1; i >= 0; i--)
    {
        ll ru = uf.root(u[x[i]]);
        ll rv = uf.root(v[x[i]]);
        if (did[ru] ^ did[rv])
        {
            if (!did[ru])
            {
                did[ru] = true;
                ans += c[ru];
            }

            if (!did[rv])
            {
                did[rv] = true;
                ans += c[rv];
            }
        }

        uf.unite(u[x[i]], v[x[i]]);
        c[uf.root(u[x[i]])] = uf.size(u[x[i]]);

        res.push_back(ans);
    }

    reverse(res.begin(), res.end());

    for (int i = 1; i <= q; i++)
    {
        cout << res[i] << endl;
    }
}