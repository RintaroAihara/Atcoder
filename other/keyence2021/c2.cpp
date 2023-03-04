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
#include <cassert>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 998244353;
const ll INF = (1ll << 60);

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

int main(void)
{
    ll h, w, k;

    cin >> h >> w >> k;

    vector<vector<char>> g(h + 1, vector<char>(w + 1, 'N'));

    for (int i = 0; i < k; i++)
    {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        g[x][y] = c;
    }

    vector<vector<ll>> dp(h + 10, vector<ll>(w + 10, 0));
    dp[0][0] = power(3, h * w - k);
    ll inv3 = power(3, MOD - 2);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (g[i][j] == 'R')
            {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
            else if (g[i][j] == 'D')
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            else if (g[i][j] == 'X')
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
            else
            {
                dp[i + 1][j] += dp[i][j] * 2 * inv3;
                dp[i + 1][j] %= MOD;
                dp[i][j + 1] += dp[i][j] * 2 * inv3;
                dp[i][j + 1] %= MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] % MOD << endl;
}