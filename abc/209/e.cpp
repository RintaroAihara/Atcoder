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
    cin >> n;

    set<string> s;
    map<string, bool> seen;
    map<string, int> num;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        num[a] = i;
        s.insert(a);
        seen[a] = false;
    }

    map<string, set<string>> mae, usiro;

    for (auto &&i : s)
    {
        mae[i.substr(0, 3)].insert(i);
        usiro[i.substr(i.size() - 3, 3)].insert(i);
    }

    vector<vector<ll>> g(s.size(), vector<ll>());

    for (auto &&i : s)
    {
        queue<string> q;
        q.push(i);

        while (q.size())
        {
            auto p = q.front();
            q.pop();

            if (seen[p])
            {
                continue;
            }

            seen[p] = true;

            for (auto &&i : mae[p.substr(p.size() - 3, 3)])
            {
                q.push(i);

                g[num[i]].push_back(num[p]);
            }
        }
    }

    vector<bool> odd_seen(n, false), even_seen(n, false), inf_seen(n, false);

    for (int i = 0; i < n; i++)
    {
        if (even_seen[i] || inf_seen[i])
        {
            continue;
        }

        queue<ll> q;
        q.push(i);
        even_seen[i] = true;

        while (q.size())
        {
            ll p = q.front();
            q.pop();

            for (auto &&j : g[p])
            {
                if (odd_seen[j] || inf_seen[j])
                {
                    continue;
                }

                if (odd_seen[p])
                {
                    even_seen[j] = true;
                }

                if (even_seen[p])
                {
                    odd_seen[j] = true;
                }

                if (inf_seen[p])
                {
                    inf_seen[j] = true;
                }

                q.push(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (odd_seen[i])
        {
            cout << "Aoki" << endl;
        }
        else if (even_seen[i])
        {
            cout << "Takahashi" << endl;
        }
        else
        {
            cout << "Draw" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (auto &&j : g[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}