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
    vector<vector<ll>> a(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<ll> point(1 << n, 0);
    vector<ll> dp(1 << n, 0);

    for (int bit = 0; bit < (1 << n); bit++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (bit & (1 << i) && bit & (1 << j))
                {
                    point[bit] += a[i][j];
                }
            }
        }
    }

    for (int bit = 0; bit < 1 << n; bit++)
    {
        int varbit = ((1 << n) - 1) ^ bit;

        for (int add = varbit; add; add = (add - 1) & varbit)
        {
            dp[bit | add] = max(dp[bit | add], dp[bit] + point[add]);
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
