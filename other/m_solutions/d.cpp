#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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

    vector<vector<ll>> g(n, vector<ll>());

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<ll> c;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ans += x;
        c.push(x);
    }

    ans -= c.top();

    queue<ll> q;
    vector<bool> searched(n, false);
    vector<ll> d(n);
    q.push(0);

    while (q.size())
    {
        ll p = q.front();
        q.pop();
        searched[p] = true;
        d[p] = c.top();
        c.pop();

        for (auto &&i : g[p])
        {
            if (!searched[i])
            {
                q.push(i);
            }
        }
    }

    cout << ans << endl;

    for (auto &&i : d)
    {
        cout << i << endl;
    }
}
