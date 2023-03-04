#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
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

    vector<vector<ll>> dp(n + 5, vector<ll>(5, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] += (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        dp[i][0] %= MOD;
        dp[i][1] += dp[i - 1][0];
        dp[i][1] %= MOD;

    }



    ll ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        ans += (a[i] * dp[i][0] % MOD) * (dp[n - i - 1][1] + dp[n - i - 1][0]) % MOD;
        ans %= MOD;
        ans -= (a[i] * dp[i][1] % MOD) * (dp[n - i - 2][1] + dp[n - i - 2][0]) % MOD;
        ans = (ans + MOD * 10ll) % MOD;
    }

    ans += a[n - 1] * dp[n - 1][0] % MOD;
    ans %= MOD;
    ans -= a[n - 1] * dp[n - 1][1] % MOD;

    ans = (ans + MOD * 10ll) % MOD;

    cout << ans << endl;
}