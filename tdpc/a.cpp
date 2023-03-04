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
    vector<ll> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<bool> dp(10001, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 10001 - 1; j >= p[i]; j--)
        {
            if (dp[j - p[i]])
            {
                dp[j] = true;
            }
        }
    }

    ll ans = 0;

    for (auto &&i : dp)
    {
        if (i)
        {
            ans++;
        }
    }

    cout << ans << endl;
}