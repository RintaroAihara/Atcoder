#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = ll(1e18) + 1;

int main(void)
{
    ll n, k;
    ll r, s, p;
    string t;
    int i, j;
    int point;
    vector<pair<ll, char>> dp;
    ll ans;

    cin >> n >> k >> r >> s >> p >> t;

    dp.resize(k);

    if (t[0] == 'r')
    {
        dp[0].first = p;
        dp[0].second = 'p';
    }
    else if (t[0] == 's')
    {
        dp[0].first = r;
        dp[0].second = 'r';
    }
    else
    {
        dp[0].first = s;
        dp[0].second = 's';
    }

    rep(i, 1, n)
    {
        if (t[i] == 'r')
        {
            if (dp[i % k].second != 'p')
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first + p, dp[i % k].first);
                dp[i % k].second = 'p';
            }
            else
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first, dp[i % k].first);
                dp[i % k].second = 'n';
            }
        }
        else if (t[i] == 's')
        {
            if (dp[i % k].second != 'r')
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first + r, dp[i % k].first);
                dp[i % k].second = 'r';
            }
            else
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first, dp[i % k].first);
                dp[i % k].second = 'n';
            }
        }
        else if (t[i] == 'p')
        {
            if (dp[i % k].second != 's')
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first + s, dp[i % k].first);
                dp[i % k].second = 's';
            }
            else
            {
                dp[i % k].first = max(dp[(i - 1 + k) % k].first, dp[i % k].first);
                dp[i % k].second = 'n';
            }
        }
    }

    ans = 0;

    rep(i, 0, k)
    {
        ans = max(ans, dp[i].first);
    }

    cout << ans << endl;
}