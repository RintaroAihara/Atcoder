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
    int n;
    cin >> n;

    vector<ll> c(n), dp(n + 1, 1);
    vector<vector<ll>> s(200010, vector<ll>());

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i];
        s[c[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        int x = lower_bound(s[c[i]].begin(), s[c[i]].end(), i) - s[c[i]].begin();
        if (x > 0)
        {
            if (s[c[i]][x] - s[c[i]][x - 1] > 1)
            {
                dp[i + 1] = dp[i] + dp[s[c[i]][x - 1] + 1];
                dp[i + 1] %= MOD;
            }
            else
            {
                dp[i + 1] = dp[i];
                dp[i + 1] %= MOD;
            }
        }
        else
        {
            dp[i + 1] = dp[i];
            dp[i + 1] %= MOD;
        }
    }

    cout << dp[n] << endl;
}
