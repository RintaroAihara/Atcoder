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

template <class S, class F>
class lazy_segmenttree
{
private:
    int size;
    int log;
    S e;
    F id;
    vector<S> data;
    vector<F> lazy;
    function<S(S, S)> op;
    function<F(F, S)> mapping;
    function<F(F, F)> transmit;

    void update(int k) { data[k] = op(data[2 * k], data[2 * k + 1]); }
    void all_apply(int k, F f)
    {
        data[k] = mapping(f, data[k]);
        if (k < size)
            lazy[k] = transmit(f, lazy[k]);
    }
    void push(int k)
    {
        all_apply(2 * k, lazy[k]);
        all_apply(2 * k + 1, lazy[k]);
        lazy[k] = id;
    }

public:
    lazy_segmenttree(int n,
                     S init,
                     F i,
                     function<S(S, S)> f,
                     function<F(F, S)> m,
                     function<F(F, F)> t) : op(f), mapping(m), transmit(t)
    {
        log = (ll)ceil(log2(n));
        size = 1 << log;
        e = init;
        id = i;
        data.assign(2 * size, e);
        lazy.assign(size, id);
    }

    void set(int p, S x)
    {
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        data[p] = x;
        for (int i = 1; i <= log; i++)
            update(p >> i);
    }

    S get(int p)
    {
        p += size;
        for (int i = log; i >= 1; i--)
            push(p >> i);
        return data[p];
    }

    S query(int l, int r)
    {
        if (l == r)
            return e;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push(r >> i);
        }

        S sml = e, smr = e;
        while (l < r)
        {
            if (l & 1)
                sml = op(sml, data[l++]);
            if (r & 1)
                smr = op(data[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return data[1]; }

    void apply(int l, int r, F f)
    {
        if (l == r)
            return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--)
        {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r)
            {
                if (l & 1)
                    all_apply(l++, f);
                if (r & 1)
                    all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++)
        {
            if (((l >> i) << i) != l)
                update(l >> i);
            if (((r >> i) << i) != r)
                update((r - 1) >> i);
        }
    }
};

int main(void)
{
    ll n, q;
    cin >> n >> q;

    lazy_segmenttree<ll, ll> s(
        n, 0, 0,
        [](ll a, ll b) { return min(a, b); },
        [](ll a, ll b) { return a + b; },
        [](ll a, ll b) { return a + b; });

    vector<ll> ans;

    for (int i = 0; i < q; i++)
    {
        int t, l, r, x;
        cin >> t;

        if (t)
        {
            cin >> l >> r;
            ans.push_back(s.query(l, r + 1));
        }
        else
        {
            cin >> l >> r >> x;
            s.apply(l, r + 1, x);
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << s.get(j);
        }

        cout << endl;
    }

    // for (auto &&i : ans)
    // {
    //     cout << i << endl;
    // }
}