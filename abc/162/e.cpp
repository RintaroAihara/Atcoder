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

ll power(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ans;
}

int main(void)
{
    ll n, k;

    cin >> n >> k;

    ll ans = 0;

    vector<ll> sum(k + 1);

    for (ll i = k; i >= 1; i--)
    {
        sum[i] = power(k / i, n);
        sum[i] %= MOD;

        for (ll j = 2 * i; j <= k; j += i)
        {
            sum[i] += MOD;
            sum[i] -= sum[j];
            sum[i] %= MOD;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        ans += (i * sum[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
