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
    ll v, e;
    cin >> v >> e;

    vector<vector<ll>> G(v, vector<ll>(v, INF)), dp(1 << v, vector<ll>(v, INF));

    dp[0][0] = 0;

    for (int i = 0; i < e; i++)
    {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    for (int i = 0; i < (1 << v); i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if ((i & (1 << k)) == 0)
                {
                    dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + G[j][k]);
                }
            }
        }
    }

    if (dp[(1 << v) - 1][0] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[(1 << v) - 1][0] << endl;
    }

    return 0;
}
