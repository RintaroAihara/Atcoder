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

int main(void)
{
    ll n;
    cin >> n;

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    vector<string> s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    dp[0][true] = dp[0][false] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == "AND")
        {
            dp[i][true] = dp[i - 1][true];
            dp[i][false] = dp[i - 1][true] + dp[i - 1][false] * 2;
        }
        else
        {
            dp[i][true] = dp[i - 1][true] * 2 + dp[i - 1][false];
            dp[i][false] = dp[i - 1][false];
        }
    }

    cout << dp[n][true] << endl;
}
