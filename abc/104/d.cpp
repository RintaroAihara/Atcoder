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
    string s;
    cin >> s;

    vector<vector<ll>> dp(4, vector<ll>(s.size() + 1, 0));

    dp[3][0] = 1;

    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i - 1] == '?')
        {
            for (int j = 0; j < 3; j++)
            {
                dp[j][i] = dp[j][i - 1] * 3 % MOD;
                dp[j][i] += dp[(j + 3) % 4][i - 1];
                dp[j][i] %= MOD;
            }
            dp[3][i] = dp[3][i - 1] * 3 % MOD;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                dp[j][i] = dp[j][i - 1];
                if (j == s[i - 1] - 'A')
                {
                    dp[j][i] += dp[(j + 3) % 4][i - 1];
                    dp[j][i] %= MOD;
                }
            }

            dp[3][i] = dp[3][i - 1];
        }
    }

    cout << dp[2][s.size()] % MOD << endl;
}
