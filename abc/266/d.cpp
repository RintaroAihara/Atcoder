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
    map<ll, P> m;
    // vector<ll> t(n), x(n), a(n);
    ll mt = 0;

    for (int i = 0; i < n; i++)
    {
        ll t, x, a;
        cin >> t >> x >> a;
        m[t] = {x, a};
        mt = max(mt, t);
    }

    vector<vector<ll>> dp(100010, vector<ll>(10, 0));

    for (int i = 1; i < 100009; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > 4 || i < j)
                {
                    continue;
                }

                if (m[i].first != j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k]);
                }
                else
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + m[i].second);
                }
            }
        }
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     cout << endl;
    // }

    ll ans = 0;

    for (int i = 0; i < 5; i++)
    {
        ans = max(ans, dp[100001][i]);
    }
    cout << ans << endl;
}