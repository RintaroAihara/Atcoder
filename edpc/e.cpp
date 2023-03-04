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
    int N, W;
    cin >> N >> W;

    vector<ll> w(N + 1), v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(100011, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 100010; j++)
        {
            if (j - v[i] < 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }

    for (int i = 100010 - 1; i >= 0; i--)
    {
        if (dp[N][i] <= W)
        {
            cout << i << endl;
            return 0;
        }
    }
}