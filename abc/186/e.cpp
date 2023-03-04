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

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<vector<ll>> dp(n + 10, vector<ll>(m + 10, INF));
    vector<int> a2, b2;

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            // A の末尾を削除
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);

            // B の末尾を削除
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            // A の末尾と B の末尾を対応させる
            if (i > 0 && j > 0)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << dp[n][m] << endl;
}
