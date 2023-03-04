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
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    vector<vector<int>> dp(2, vector<int>(110, 1 << 30));

    if (a == b)
    {
        cout << x << endl;
        return 0;
    }
    else if (a > b)
    {
        dp[0][a] = 0;
        dp[1][a] = x;
        for (int i = a - 1; i >= b; i--)
        {
            dp[1][i] = min(dp[1][i + 1] + y, dp[0][i + 1] + x);
            dp[0][i] = min(dp[0][i + 1] + y, dp[1][i] + x);
        }

        cout << dp[1][b] << endl;
        return 0;
    }
    else
    {
        dp[0][a] = 0;
        dp[1][a] = x;
        for (int i = a + 1; i <= b; i++)
        {
            dp[0][i] = min(dp[0][i - 1] + y, dp[1][i - 1] + x);
            dp[1][i] = min(dp[1][i - 1] + y, dp[0][i] + x);
        }

        cout << dp[1][b] << endl;
        return 0;
    }
}
