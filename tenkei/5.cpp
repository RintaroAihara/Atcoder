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
    ll n, b, k;
    cin >> n >> b >> k;

    vector<ll> c(k);

    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }

    vector<vector<ll>> dp(n + 5, vector<ll>(b + 5, 0));

    dp[0][0] = 1;

    ll ten = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int l = 0; l < k; l++)
            {
                dp[i][j] += dp[i - 1][((j - c[l] * ten) % b + b) % b];
                dp[i][j] %= MOD;
            }
        }

        ten *= 10;
        ten %= b;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%lld ", dp[i][j]);
        }
        cout << endl;
    }

    cout << dp[n][0] << endl;
}