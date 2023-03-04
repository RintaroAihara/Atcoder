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
const ll MOD = 998244353;
const ll INF = (1ll << 60);

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<ll> l(k), r(k), dp(n , 0), s(n +1, 0);

    for (int i = 0; i < k; i++)
    {
        cin >> l[i] >> r[i];
    }

    dp[0] = 1;
    s[1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ll x, y;

            if (i - l[j] < 0)
            {
                continue;
            }

            x = i - l[j] + 1; //big
            y = max(i - r[j], 0ll);     //small

            dp[i] += s[x] - s[y] + MOD;
            dp[i] %= MOD;
        }

        s[i + 1] = s[i] + dp[i] + MOD;
        s[i + 1] %= MOD;
    }

    cout << dp[n - 1] << endl;
}
