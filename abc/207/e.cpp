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

    vector<ll> s;

    s.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        s[i + 1] = s[i] + a[i];
    }

    ll ans = 0;

    vector<vector<ll>> dp(n + 2, vector<ll>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        vector<ll> m(n, 0);

        for (int j = 0; j <= n; j++)
        {
            dp[i + 1][j] += m[s[j + 1] % (i + 1)];
            dp[i + 1][j] %= MOD;
            m[s[j + 1] % (i + 1)] += dp[i][j];
            m[s[j + 1] % (i + 1)] %= MOD;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][n - 1];
        ans %= MOD;
    }

    cout << ans << endl;
}
