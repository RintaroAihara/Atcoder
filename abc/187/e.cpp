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

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n, 0), rank(n), z(n, 0);
    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    rank[0] = 0;

    queue<int> que;
    que.push(0);
    vector<bool> searched(n, false);
    ll max_rank = 0;

    while (que.size())
    {
        int p = que.front();
        que.pop();
        searched[p] = true;

        for (auto &&i : g[p])
        {
            if (!searched[i])
            {
                que.push(i);
                rank[i] = rank[p] + 1;
                max_rank = max(max_rank, rank[i]);
            }
        }
    }

    ll q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        ll t, e, x;
        cin >> t >> e >> x;
        e--;

        if (t == 1)
        {
            if (rank[a[e]] < rank[b[e]])
            {
                z[0] += x;
                z[b[e]] -= x;
            }
            else
            {
                z[a[e]] += x;
            }
        }
        else
        {
            if (rank[b[e]] < rank[a[e]])
            {
                z[0] += x;
                z[a[e]] -= x;
            }
            else
            {
                z[b[e]] += x;
            }
        }
    }

    que.push(0);
    searched.assign(n, false);

    while (que.size())
    {
        int p = que.front();
        que.pop();
        searched[p] = true;
        c[p] = z[p];

        for (auto &&i : g[p])
        {
            if (!searched[i])
            {
                que.push(i);
                z[i] += z[p];
            }
        }
    }

    for (auto &&i : c)
    {
        cout << i << endl;
    }
}
