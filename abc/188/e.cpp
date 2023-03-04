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
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
    }

    vector<ll> dp(n, INF);

    for (int i = 0; i < n; i++)
    {
        for (auto &&j : g[i])
        {
            dp[j] = min({dp[j], dp[i], a[i]});
        }
    }

    ll ans = -INF;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] - dp[i]);
    }

    cout << ans << endl;
}
