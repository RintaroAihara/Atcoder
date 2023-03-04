#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
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
    ll n, l;

    cin >> n >> l;

    vector<bool> x(l, false);

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        x[a] = true;
    }

    ll t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    vector<ll> dp(l + 20, INF);

    dp[0] = 0;

    for (int i = 0; i < l; i++)
    {
        if (x[i + 1])
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + t1 + t3);
        }
        else
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + t1);
        }

        if (x[i + 2])
        {
            dp[i + 2] = min(dp[i + 2], dp[i] + t1 + t2 + t3);
        }
        else
        {
            if (i + 2 > l)
            {
                dp[l] = min(dp[l], dp[i] + t1 / 2 + ((l - i) * 2 - 1) * t2 / 2);
            }
            else
            {
                dp[i + 2] = min(dp[i + 2], dp[i] + t1 + t2);
            }
        }

        if (x[i + 4])
        {
            dp[i + 4] = min(dp[i + 4], dp[i] + t1 + t2 * 3 + t3);
        }
        else
        {
            if (i + 4 > l)
            {
                dp[l] = min(dp[l], dp[i] + t1 / 2 + ((l - i) * 2 - 1) * t2 / 2);
            }
            else
            {
                dp[i + 4] = min(dp[i + 4], dp[i] + t1 + t2 * 3);
            }
        }
    }

    // for (int i = 0; i <= l; i++)
    // {
    //     cout << dp[i] << endl;
    // }

    cout << dp[l] << endl;
}
