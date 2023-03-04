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

struct fenwick_tree
{
    typedef int T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num + 1, 0) { n = num; }

    // a_i += w
    void add(T i, T w)
    {
        for (T x = i; x <= n; x += x & -x)
        {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i)
    {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x)
        {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right)
    {
        return sum(right) - sum(left);
    }
};

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        // p[i]--;
    }

    fenwick_tree f_tree(n);

    ll inversion = 0;

    for (int j = 0; j < n; j++)
    {
        inversion += j - f_tree.sum(p[j]);
        f_tree.add(p[j], 1);
    }

    if (inversion != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        // cin >> p[i];
        p[i]--;
    }


    vector<ll> ans;
    queue<ll> q;

    for (int i = 0; i < n - 1; i++)
    {
        q.push(i);
    }

    map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        m[p[i]] = i;
    }

    vector<bool> used(n + 1, false);

    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        while (m[i] != i)
        {
            // for (auto &&z : ans)
            // {
            //     cout << z << endl;
            // }

            if (m[i] > i)
            {

                ll a = p[m[i]];
                ll b = p[m[i] - 1];
                ans.push_back(m[i]);
                swap(p[m[i]], p[m[i] - 1]);
                swap(m[a], m[b]);
            }
            else
            {
                ll a = p[m[i]];
                ll b = p[m[i] + 1];
                ans.push_back(m[i] + 1);
                swap(p[m[i]], p[m[i] + 1]);
                swap(m[a], m[b]);
            }
        }
    }

    for (auto &&i : ans)
    {
        cout << i << endl;
    }
}
