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
    vector<ll> t(n);

    ll s = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        s += t[i];
    }

    vector<vector<bool>> dp(n + 5, vector<bool>(100010, false));

    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = true;
        for (int j = 0; j < 100005; j++)
        {
            dp[i][j] = dp[i - 1][j] | dp[i][j];
            if (j - t[i - 1] < 0)
            {
                continue;
            }
            
            dp[i][j] = dp[i - 1][j - t[i - 1]] | dp[i][j];
        }
    }

    ll ans = INF;

    for (ll i = 0; i < 100005; i++)
    {
        if (dp[n][i])
        {
            chmin(ans, max(s - i, i));
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
}
