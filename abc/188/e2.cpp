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
    int n, m;

    cin >> n >> m;

    vector<vector<ll>> g(n, vector<ll>());
    vector<P> a(n), _a;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }

    _a = a;

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
    }

    vector<bool> searched(n, false);
    vector<ll> dp(n, INF);

    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(a[i].second);
        ll x = a[i].first;

        while (q.size())
        {
            int p = q.front();
            q.pop();

            for (auto &&j : g[p])
            {
                if (searched[j])
                {
                    continue;
                }
                searched[j] = true;

                dp[j] = x;
                q.push(j);
            }
        }
    }

    ll ans = -INF;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, _a[i].first - dp[i]);
    }

    cout << ans << endl;
}
