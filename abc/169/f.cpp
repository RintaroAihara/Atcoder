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
    ll n, s;
    cin >> n >> s;

    vector<ll> a(n), sum(n + 1);
    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    map<ll, ll> c;

    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (sum[j] - sum[i] == s)
            {
                c[j - i]++;
            }
        }
    }

    ll ans = 0;

    for (auto x : c)
    {
        ans += (power(2, n - x.first) * x.second)%MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
