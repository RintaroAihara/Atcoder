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

//初期化例 segmenttree<bitset<26>> seg(n, 0, [](bitset<26> a, bitset<26> b) { return a | b; });

int main(void)
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll ma = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        ma = max(ma, a[i]);
    }

    segmenttree<ll> s(ma + 1, 0, [](ll a, ll b) { return max(a, b); });

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll l, r;

        l = max(a[i] - k, 0ll);
        r = min(a[i] + k + 1, ma + 1);

        s.set(a[i], s.query(l, r) + 1);
        ans = max(ans, s.get(a[i]));
    }

    cout << ans << endl;
}