#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define ran(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main(void)
{
    ll N, W;
    cin >> N >> W;

    vector<ll> w(N + 1), v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j - w[i] < 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[N][W] << endl;
}