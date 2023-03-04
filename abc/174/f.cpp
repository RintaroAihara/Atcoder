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
#include <stack>
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
    ll n;

public:
    using F = function<T(T, T)>;

    T dif;
    F f;
    vector<T> st;

    segmenttree(ll size, T init, F f) : f(f)
    {
        n = 1;

        while (n < size)
        {
            n *= 2;
        }

        st.assign(2 * n - 1, init);
    }

    void set(ll i, T x)
    {
        st[i + n - 1] = x;
    }

    void build()
    {
        for (ll i = n - 2; i >= 0; i--)
        {
            st[i] = f(st[i * 2 + 1], st[i * 2 + 2]);
        }
    }

    void update(ll i, T x)
    {
        i += n - 1;
        st[i] = x;

        while (i > 0)
        {
            i = (i - 1) / 2;
            st[i] = f(st[2 * i + 1], st[2 * i + 2]);
        }
    }

    T query(ll a, ll b)
    {
        return query_(a, b, 0, 0, n);
    }

    T query_(ll a, ll b, ll k, ll l, ll r)
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
};

//初期化例 segmenttree<bitset<26>> seg(n, 0, [](bitset<26> a, bitset<26> b) { return a | b; });

int main(void)
{
    ll n, q;
    vector<ll> ans;

    cin >> n >> q;

    vector<ll> c(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    segmenttree<bitset<500010>> seg(n, 0, [](bitset<500010> a, bitset<500010> b) { return a | b; });
    seg.dif = 0;

    for (ll i = 0; i < n; i++)
    {
        bitset<500010> bit;
        bit.set(c[i]);
        seg.set(i, bit);
    }

    seg.build();

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        ll an = 0;

        cin >> l >> r;
        l--;

        bitset<500010> bit = seg.query(l, r);

        an = bit.count();

        ans.push_back(an);
    }

    for (auto &z : ans)
    {
        cout << z << endl;
    }
}