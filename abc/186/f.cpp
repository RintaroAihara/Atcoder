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

template <typename T>
class segmenttree
{
private:
    using F = function<T(T, T)>;
    int n;
    T dif;
    F f;
    vector<T> st;

    T query_(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
        {
            return dif;
        }

        if (a <= l && r <= b)
        {
            return st[k];
        }
        else
        {
            T x = query_(a, b, 2 * k + 1, l, (l + r) / 2);
            T y = query_(a, b, 2 * k + 2, (l + r) / 2, r);

            return f(x, y);
        }
    }

    void build()
    {
        for (int i = n - 2; i >= 0; i--)
        {
            st[i] = f(st[i * 2 + 1], st[i * 2 + 2]);
        }
    }

public:
    segmenttree(int size, T init, F f) : f(f)
    {
        n = 1;

        while (n < size)
        {
            n *= 2;
        }

        dif = init;
        st.assign(2 * n - 1, init);

        build();
    }

    void set(int i, T x)
    {
        i += n - 1;
        st[i] = x;

        while (i > 0)
        {
            i = (i - 1) / 2;
            st[i] = f(st[2 * i + 1], st[2 * i + 2]);
        }
    }

    T get(int i)
    {
        return st[i + n - 1];
    }

    T query(int a, int b)
    {
        return query_(a, b, 0, 0, n);
    }
};

//初期化例
//segmenttree<bitset<26>> seg(n, 0, [](bitset<26> a, bitset<26> b) { return a | b; });

int main(void)
{
    ll h, w, m;
    cin >> h >> w >> m;

    vector<ll> row(h, w), col(w, h);

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        chmin(row[x], y);
        chmin(col[y], x);
    }

    ll ans = 0;

    segmenttree<ll> seg(w, 0, [](ll a, ll b) { return a + b; });

    for (int i = 0; i < col[0]; i++)
    {
        ans += row[i];
    }

    for (int i = 0; i < row[0]; i++)
    {
        ans += col[i];
    }

    for (int i = 0; i < row[0]; i++)
    {
        seg.set(i, 1);
    }

    vector<vector<int>> ends(h + 1);

    for (int i = 0; i < row[0]; i++)
    {
        ends[col[i]].push_back(i);
    }

    for (int i = 0; i < col[0]; i++)
    {
        for (auto &&j : ends[i])
        {
            seg.set(j, 0);
        }

        ans -= seg.query(0, row[i]);
    }

    cout << ans << endl;
}