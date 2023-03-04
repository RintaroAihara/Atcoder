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
    ll h, w;
    cin >> h >> w;

    vector<vector<char>> g(h + 1, vector<char>(w + 1));
    vector<vector<ll>> dp(h + 1, vector<ll>(w + 1, 0));
    vector<vector<ll>> dp_h(h + 1, vector<ll>(w + 1, 0));
    vector<vector<ll>> dp_w(h + 1, vector<ll>(w + 1, 0));
    vector<vector<ll>> dp_d(h + 1, vector<ll>(w + 1, 0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> g[i][j];
        }
    }

    dp[0][0] = 1;
    dp_h[0][0] = 1;
    dp_w[0][0] = 1;
    dp_d[0][0] = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (g[i][j] == '#')
            {
                dp_h[i][j] = 0;
                dp_w[i][j] = 0;
                dp_d[i][j] = 0;
                continue;
            }

            if (j > 0)
            {
                dp[i][j] += dp_w[i][j - 1];
                dp[i][j] %= MOD;
            }

            if (i > 0)
            {
                dp[i][j] += dp_h[i - 1][j];
                dp[i][j] %= MOD;
            }

            if (i > 0 && j > 0)
            {
                dp[i][j] += dp_d[i - 1][j - 1];
                dp[i][j] %= MOD;
            }

            if (j > 0)
            {
                dp_w[i][j] += dp[i][j] + dp_w[i][j - 1];
                dp_w[i][j] %= MOD;
            }

            if (i > 0)
            {
                dp_h[i][j] += dp[i][j] + dp_h[i - 1][j];
                dp_h[i][j] %= MOD;
            }

            if (i > 0 && j > 0)
            {
                dp_d[i][j] += dp[i][j] + dp_d[i - 1][j - 1];
                dp_d[i][j] %= MOD;
            }

            if (dp_h[i][j] == 0)
            {
                dp_h[i][j] = dp[i][j];
            }

            if (dp_w[i][j] == 0)
            {
                dp_w[i][j] = dp[i][j];
            }

            if (dp_d[i][j] == 0)
            {
                dp_d[i][j] = dp[i][j];
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;
}
