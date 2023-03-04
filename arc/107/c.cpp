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
const ll MOD = 998244353;
const ll INF = (1ll << 60);

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

ll factorial(ll x)
{
    ll res = 1;

    for (int i = 1; i <= x; i++)
    {
        res *= i;
        res %= MOD;
    }

    return res;
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    unionfind row(n), column(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool flag = true;
            for (int l = 0; l < n; l++)
            {
                if (a[l][i] + a[l][j] > k)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                row.unite(i, j);
            }

            flag = true;
            for (int l = 0; l < n; l++)
            {
                if (a[i][l] + a[j][l] > k)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                column.unite(i, j);
            }
        }
    }

    set<int> row_p, column_p;

    for (int i = 0; i < n; i++)
    {
        row_p.insert(row.root(i));
        column_p.insert(column.root(i));
    }

    ll R = 1, C = 1;

    for (auto &&i : row_p)
    {
        R *= factorial(row.size(i));
        R %= MOD;
    }

    for (auto &&i : column_p)
    {
        C *= factorial(column.size(i));
        C %= MOD;
    }

    cout << R * C % MOD << endl;
}
