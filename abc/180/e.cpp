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
    ll n;
    cin >> n;

    vector<ll> x(n), y(n), z(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    vector<vector<ll>> G(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + max(0ll, z[i] - z[j]);
        }
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));

    dp[0][0] = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((i & (1 << k)) == 0)
                {
                    dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + G[j][k]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << endl;
}
