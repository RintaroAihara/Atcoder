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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 60);

namespace atcoder
{
    template <typename T>
    bool chmax(T &a, const T &b)
    {
        if (a < b)
        {
            a = b; // aをbで更新
            return true;
        }
        return false;
    }

    template <typename T>
    bool chmin(T &a, const T &b)
    {
        if (a > b)
        {
            a = b; // aをbで更新
            return true;
        }
        return false;
    }

    ll power(ll x, ll y)
    {
        ll ans = 1;
        while (y)
        {
            if (y & 1)
                ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return ans;
    }

    ll power(ll x, ll y, ll mod)
    {
        ll ans = 1;
        while (y)
        {
            if (y & 1)
                ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return ans;
    }

    ll lcm(ll a, ll b)
    {
        return a * b / gcd(a, b);
    }

    vector<ll> divisor(ll n)
    {
        vector<ll> ret;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ret.push_back(i);
                if (i * i != n)
                    ret.push_back(n / i);
            }
        }
        sort(begin(ret), end(ret));
        return (ret);
    }

    ll extGCD(ll a, ll b, ll &x, ll &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        ll d = extGCD(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    inline ll mod(ll a, ll m)
    {
        return (a % m + m) % m;
    }

    ll modinv(ll a, ll m)
    {
        ll x, y;
        extGCD(a, m, x, y);
        return mod(x, m);
    }

    class unionfind
    {
    private:
        vector<ll> d;

    public:
        unionfind(ll n) : d(n, -1) {}

        ll root(ll x)
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

        bool unite(ll x, ll y)
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

        bool same(ll x, ll y)
        {
            return root(x) == root(y);
        }

        ll size(ll x)
        {
            return -d[root(x)];
        }
    };

    class Max_flow
    {
    private:
        struct edge
        {
            int to;
            ll cap;
            int rev;
        };

        int n;
        vector<vector<edge>> G;
        vector<int> level;
        vector<int> iter;

        void bfs(int s)
        {
            level.assign(n, -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);

            while (q.size())
            {
                int v = q.front();
                q.pop();

                for (int i = 0; i < (int)G[v].size(); i++)
                {
                    edge e = G[v][i];

                    if (e.cap > 0 && level[e.to] < 0)
                    {
                        level[e.to] = level[v] + 1;
                        q.push(e.to);
                    }
                }
            }
        }

        int dfs(int v, int t, ll f)
        {
            if (v == t)
            {
                return f;
            }

            for (int &i = iter[v]; i < (int)G[v].size(); i++)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && level[v] < level[e.to])
                {
                    ll d = dfs(e.to, t, min(f, e.cap));

                    if (d > 0)
                    {
                        e.cap -= d;
                        G[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }

            return 0;
        }

    public:
        Max_flow(int n) : n(n), G(n, vector<edge>()) {}

        void add_edge(int from, int to, ll cap)
        {
            G[from].push_back({to, cap, (int)G[to].size()});
            G[to].push_back({from, 0, (int)G[from].size() - 1});
        }

        int max_flow(int s, int t)
        {
            ll flow = 0;

            while (true)
            {
                bfs(s);
                if (level[t] < 0)
                {
                    return flow;
                }

                iter.assign(n, 0);
                ll f = 0;

                while ((f = dfs(s, t, INF)) > 0)
                {
                    flow += f;
                }
            }
        }
    };

    class eratosthenes
    {
    private:
        int n;
        vector<int> f;
        vector<P> primes;

    public:
        eratosthenes(int n) : f(n + 1)
        {
            ll i, j;
            f[0] = f[1] = -1;
            for (i = 2; i <= n; i++)
            {
                if (!f[i])
                {
                    f[i] = i;
                    primes.push_back(P(i, 0));
                    for (j = i * i; j <= n; j += i)
                    {
                        if (!f[j])
                        {
                            f[j] = i;
                        }
                    }
                }
            }
        }

        vector<int> genosis(int x)
        {
            vector<int> g;

            while (x != 1)
            {
                g.push_back(f[x]);
                x /= f[x];
            }

            return g;
        }

        vector<P> genosis_count(int x)
        {
            vector<P> gc;
            vector<int> g = genosis(x);

            if (g.empty() == 1)
            {
                return {};
            }

            gc.push_back(P(f[x], 0));

            for (auto &i : g)
            {
                if (gc.back().first == i)
                {
                    gc.back().second++;
                }
                else
                {
                    gc.push_back(P(i, 1));
                }
            }

            return gc;
        }
    };

    class factorial
    {
    private:
        vector<ll> fac, finv, inv;

    public:
        factorial(int n) : fac(2, 1), finv(2, 1), inv(2, 1)
        {
            int i;

            for (int i = 2; i <= n; i++)
            {
                fac.push_back(fac[i - 1] * i % MOD);
                inv.push_back(MOD - inv[MOD % i] * (MOD / i) % MOD);
                finv.push_back(finv[i - 1] * inv[i] % MOD);
            }
        }

        ll comb(int n, int k)
        {
            if (n < k)
            {
                return 0;
            }

            if (n < 0 || k < 0)
            {
                return 0;
            }

            return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
        }

        ll perm(int n, int k)
        {
            if (n < k)
            {
                return 0;
            }

            if (n < 0 || k < 0)
            {
                return 0;
            }

            return fac[n] * finv[n - k] % MOD;
        }
    };

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

} // namespace atcoder
using namespace atcoder;

int main(void)
{
    int n, m;

    cin >> n >> m;

    unionfind uf(n);
    vector<int> a(m), b(m);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;

        uf.unite(a[i], b[i]);
    }

    
}