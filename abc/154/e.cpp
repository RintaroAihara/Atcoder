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
    string n;
    ll k;
    cin >> n >> k;

    vector<vector<vector<ll>>> dp(n.size() + 1, vector<vector<ll>>(5, vector<ll>(2, -INF)));

    dp[n.size()][0][0] = 1;

    for (int i = n.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= k; j++)
        {
            ll x = n[i] - '0';

            if (x == 0)
            {
                dp[i][j + 1][0] += dp[i + 1][j][0];
                dp[i][j][1] += dp[i + 1][j][0] * 9;
            }
            else
            {
                dp[i][j][0] += dp[i + 1][j][0];
                dp[i][j][1] += dp[i + 1][j][1] * 9 + dp[i + 1][j][0] * (x - 1);
                dp[i][j + 1][1] += dp[i + 1][j][1];
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << dp[0][i][0] + dp[0][i][1] << endl;
    }
}