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
ll MOD;
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
    ll k;
    cin >> k;

    MOD = k;

    ll ans = 7;

    for (ll i = 1; i < 1000010; i++)
    {

        if (ans % k == 0)
        {
            cout << i  << endl;
            return 0;
        }

        ans += 7 * power(10, i);

        ans %= MOD;
    }

    cout << -1 << endl;
}
