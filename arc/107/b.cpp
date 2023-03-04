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
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    for (ll x = 2; x <= 2 * n; x++)
    {
        ll y = x - k;

        if (y < 2 || y > 2 * n)
        {
            continue;
        }

        ll X, Y;

        if (x - 1 > n)
        {
            X = 2 * n - x + 1;
        }
        else
        {
            X = x - 1;
        }

        if (y - 1 > n)
        {
            Y = 2 * n - y + 1;
        }
        else
        {
            Y = y - 1;
        }

        ans += X * Y;
    }

    cout << ans << endl;
}
