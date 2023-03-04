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
    int N, W;
    vector<int> w(110);
    vector<int> v(110);
    vector<ll> dp(100010, MOD);
    int i, j, k;
    ll ans = 0;
    ll sum = 0;

    cin >> N >> W;

    ran(i, 1, N)
    {
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    dp[0] = 0;

    for (i = 1; i <= N; i++)
    {
        for (j = sum; j >= v[i]; j--)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for (i = 1; i <= sum; i++)
    {
        if (dp[i] <= W)
        {
            ans = max(ans, (ll)i);
        }
    }

    cout << ans << endl;
}