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

ll comb(ll n, ll k)
{
    ll ans = 1;
    ll i;

    if (n < k || n < 0 || k < 0)
    {
        return 0;
    }

    rep(i, 0, k)
    {
        ans *= n - i;
        ans %= MOD;
        ans *= power(i + 1, MOD - 2);
        ans %= MOD;
    }

    return ans;
}

int main(void)
{
    int n, m;

    cin >> n >> m;

    cout << n * (n - 1) / 2 + m * (m - 1) / 2 << endl;
}