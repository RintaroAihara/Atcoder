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
    vector<vector<ll>> s(h + 10, vector<ll>(w + 10, 0));

    for (int i = 0; i < k; i++)
    {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        g[x][y] = c;
    }

    for (int i = 0; i < w; i++)
    {
        g[h][i] = 'X';
    }

    for (int i = 0; i < h; i++)
    {
        g[i][w] = 'X';
    }

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (g[i][j] == 'N')
            {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + 1;
            }
            else
            {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j];
            }
        }
    }

    vector<vector<ll>> dp(h + 10, vector<ll>(w + 10, 0));
    dp[0][0] = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // cout << i << j << endl;
            // cout << s[i][j + 2] - s[0][j + 2] - s[i][j + 1] + s[0][j + 1] << endl;
            // cout << s[i + 2][j] - s[i + 2][0] - s[i + 1][j] + s[i + 1][0] << endl;

            if (g[i][j] == 'R')
            {
                dp[i][j + 1] += dp[i][j] * power(3, s[i][j + 2] - s[0][j + 2] - s[i][j + 1] + s[0][j + 1]) % MOD;
                dp[i][j + 1] %= MOD;
            }
            else if (g[i][j] == 'D')
            {
                dp[i + 1][j] += dp[i][j] * power(3, s[i + 2][j] - s[i + 2][0] - s[i + 1][j] + s[i + 1][0]) % MOD;
                dp[i + 1][j] %= MOD;
            }
            else if (g[i][j] == 'X')
            {
                dp[i][j + 1] += dp[i][j] * power(3, s[i][j + 2] - s[0][j + 2] - s[i][j + 1] + s[0][j + 1]) % MOD;
                dp[i][j + 1] %= MOD;
                dp[i + 1][j] += dp[i][j] * power(3, s[i + 2][j] - s[i + 2][0] - s[i + 1][j] + s[i + 1][0]) % MOD;
                dp[i + 1][j] %= MOD;
            }
            else
            {
                dp[i][j + 1] += (dp[i][j] * 2 % MOD) * power(3, s[i][j + 2] - s[0][j + 2] - s[i][j + 1] + s[0][j + 1]) % MOD;
                dp[i][j + 1] %= MOD;
                dp[i + 1][j] += (dp[i][j] * 2 % MOD) * power(3, s[i + 2][j] - s[i + 2][0] - s[i + 1][j] + s[i + 1][0]) % MOD;
                dp[i + 1][j] %= MOD;
            }
        }
    }

    if (g[h - 1][w - 1] == 'N')
    {
        dp[h - 1][w - 1] *= 3;
    }

    cout << dp[h - 1][w - 1] % MOD << endl;
}