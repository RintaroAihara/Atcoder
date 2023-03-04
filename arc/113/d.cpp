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
const ll MOD = 998244353;
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
    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;

    if (n == 1 && m == 1)
    {
        cout << k << endl;
        return 0;
    }

    if (n == 1)
    {
        ans += (power(k, m) - power(k - 1, m) + MOD) % MOD;
        ans %= MOD;
    }
    else if (m == 1)
    {
        ans = 1;
    }
    else
    {
        ans += power(k, m);
        ans %= MOD;
    }

    for (int i = 2; i <= k; i++)
    {
        ll a = (power(i, n) - power(i - 1, n) + MOD) % MOD;

        ll b;

        if (n == 1)
        {
            b = (power(k - i + 1, m) - power(k - i + 1 - 1, m) + MOD) % MOD;
        }
        else if (m == 1)
        {
            b = 1;
        }
        else
        {
            b = power(k - i + 1, m);
        }

        ans += (a * b) % MOD;
        ans %= MOD;
        // cout << a << endl;
        // cout << b << endl;
    }

    cout << ans << endl;
}