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
    ll t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll n, a, b;
        cin >> n >> a >> b;

        ll x, y, z, w, u;

        if (a > b)
        {
            swap(a, b);
        }

        x = power(n - a + 1, 2);
        y = power(n - b + 1, 2);
        z = power(a + b - 1, 2);
        w = power(n + a - 1, 2);

        ll ans = (x * y % MOD) - (z * y % MOD) + (w - x) % MOD;
        ans %= MOD;
        ans = (ans + MOD * 10) % MOD;
        cout << ((w - x) + MOD) % MOD << " " << (x * y % MOD) - (z * y % MOD) << endl;

        for (int j = 0; j < 1000000000; j++)
        {
            ll r = (w - x)* j + (x * y % MOD) - (z * y % MOD);
            r %= MOD;
            r = (r + MOD) % MOD;
            if (r % MOD == 409369707)
            {
                cout << j << endl;
            }
        }
    }
}
