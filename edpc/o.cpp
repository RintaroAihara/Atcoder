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

int main(void)
{
    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1 << n, 0);

    dp[0] = 1;

    for (int i = 1; i < (1 << n); i++)
    {
        int p = __builtin_popcount(i);

        for (int j = 0; j < n; j++)
        {
            if ((a[p - 1][j] << j) & i)
            {
                dp[i] += dp[i ^ (a[p - 1][j] << j)];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}