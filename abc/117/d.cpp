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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> bit(60, vector<ll>(2, 0));

    for (ll i = 0; i < 60; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] & (1ll << i))
            {
                bit[i][1]++;
            }
            else
            {
                bit[i][0]++;
            }
        }
    }

    vector<vector<ll>> dp(60, vector<ll>(2, -INF));

    dp[51][0] = 0;

    for (ll i = 50; i >= 0; i--)
    {
        ll mask = 1ll << i;

        if (dp[i + 1][1] >= 0)
        {
            chmax(dp[i][1], dp[i + 1][1] + mask * max(bit[i][0], bit[i][1]));
        }

        if (dp[i + 1][0] >= 0)
        {
            if (mask & k)
            {
                chmax(dp[i][0], dp[i + 1][0] + mask * bit[i][0]);
                chmax(dp[i][1], dp[i + 1][0] + mask * bit[i][1]);
            }
            else
            {
                chmax(dp[i][0], dp[i + 1][0] + mask * bit[i][1]);
            }
        }
    }

    cout << max(dp[0][1], dp[0][0]) << endl;
}