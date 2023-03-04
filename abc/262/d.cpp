#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 998244353;
const ll INF = (1ll << 60);

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main(void)
{
    ll n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        vector<vector<vector<ll>>> dp(n + 3, vector<vector<ll>>(n + 3, vector<ll>(n + 2, 0)));

        for (int j = 0; j <= n; j++)
        {
            dp[0][j][0] = 1;
        }

        for (ll j = 0; j < n; j++)
        {
            for (ll k = 1; k <= n; k++)
            {
                for (ll l = 0; l < n; l++)
                {
                    dp[j + 1][k][l] += dp[j][k - 1][(l - a[j - 1] + i * 10000000000ll) % i];
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < i; k++)
            {
                printf("%lld ", dp[j][2][k]);
            }
            cout << endl;
        }
        cout << endl;

        // for (int j = 0; j < n; j++)
        // {

        // }

        ans += dp[n][n][0];
        cout << ans << endl;
    }

    cout << ans << endl;
}