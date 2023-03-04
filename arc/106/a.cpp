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
    ll n;
    cin >> n;

    ll x = 0, y = 1;

    while (y < n)
    {
        y *= 3;
        x++;
    }

    ll p = 3;

    for (ll a = 1; a <= x; a++)
    {
        ll m = n - powl(3, a);
        ll b = 0;

        if (m < 5)
        {
            break;
        }

        while (m % 5 == 0)
        {
            m /= 5;
            b++;

            if (m == 1)
            {
                printf("%lld %lld\n", a, b);
                return 0;
            }
        }

        p *= 3;
    }

    cout << -1 << endl;
}
